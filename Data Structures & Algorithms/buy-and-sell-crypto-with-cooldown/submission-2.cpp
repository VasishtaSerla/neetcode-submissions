class Solution {
public:
    int ans(vector<int>& prices,int index, int buy, vector<vector<int>>&mem){
        //buy = 1 -> can buy else buy = 0 -> sell
        if(index>=prices.size())return 0;
        if(mem[index][buy]!=-1)return mem[index][buy];
        if(buy){
            int x = -1*prices[index] + ans(prices,index+1,0,mem);
            int y = ans(prices,index+1,1,mem);
            return mem[index][buy] = max(x,y);
        }
        else {
            int x = prices[index] + ans(prices,index+2,1,mem);
            int y = ans(prices,index+1,0,mem);
            return mem[index][buy] = max(x,y);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>mem(prices.size(),vector<int>(2,-1));
        return ans(prices,0,1,mem);
    }
};
