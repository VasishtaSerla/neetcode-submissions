class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        vector<int>profit;
        for(auto x:prices){
           if(x<min)min = x;
           profit.push_back(x-min);
       }        
       return *max_element(profit.begin(),profit.end());
    }
};