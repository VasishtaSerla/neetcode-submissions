class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        vector<pair<int,int>>p;
        for(int i = 0; i<length; i++){
            p.push_back({heights[i],i});
        }
        vector<int>lb(length),rb(length);
        stack<pair<int,int>>ls,rs;
        //left bounday indices
         for(int i = length-1 ; i>=0; i--){
           if(ls.empty()){
               ls.push({heights[i],i});
               continue;
           }
           while(!ls.empty() &&  heights[i] < ls.top().first){
            lb[ls.top().second] = i+1;
            ls.pop();
        }
          ls.push({heights[i],i});

        }
        while(!ls.empty()){
            lb[ls.top().second] = 0;
            ls.pop();
        }
        //right indices

         for(int i = 0 ; i<length; i++){
           if(rs.empty()){
               rs.push({heights[i],i});
               continue;
           }
           while(!rs.empty() && heights[i] < rs.top().first){
            rb[rs.top().second] = i-1;
            rs.pop();
        }
          rs.push({heights[i],i});

        }
        while(!rs.empty()){
            rb[rs.top().second] = length-1;
            rs.pop();
        }
        vector<int>areas(length);
        for(int i = 0; i<length; i++){
            areas[i] = (rb[i]-lb[i]+1)*heights[i];
        }
         return *(max_element(areas.begin(),areas.end()));
    }
};