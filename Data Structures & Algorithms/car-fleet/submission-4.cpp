class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        for(int i = 0; i<position.size(); i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end());
        stack<pair<int,int>>s;
        for(auto x:cars){
            if(s.empty()){
                s.push(x);
                continue;
            }
            if(x.second < s.top().second){
                while(s.size() && x.second<s.top().second  &&  (((double)(x.first - s.top().first) / (s.top().second - x.second))* s.top().second + s.top().first) <= target){
                    s.pop();
                }
               s.push(x);
            }
            else s.push(x);
        }
        return s.size();
    }
};