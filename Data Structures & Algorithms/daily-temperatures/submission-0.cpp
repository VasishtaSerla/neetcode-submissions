class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        int length = temperatures.size();
        vector<int>ans(length);
        for(int i = 0; i<length; i++){
          if(s.empty()){s.push({temperatures[i],i});
          continue;
        }
        if(temperatures[i]<=s.top().first)s.push({temperatures[i],i});
        else{
            while (!s.empty() &&  temperatures[i] > s.top().first)
            {
                /* code */
                int val = i - s.top().second;
                ans[s.top().second] = val;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
    
    }
    while(!s.empty()){
       ans[s.top().second] = 0;
       s.pop();
    }
    return ans;
    }
};