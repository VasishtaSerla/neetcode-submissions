class Solution {
public:
    int ans(int amount, vector<int>& coins,int index,vector<vector<int>>&mem){
       if(amount == 0)return 1;
       if(amount < 0 || index==coins.size())return 0;
       if(mem[index][amount]!=-1)return mem[index][amount];
       return mem[index][amount] = ans(amount-coins[index],coins,index,mem)+ans(amount,coins,index+1,mem);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>mem(coins.size(),vector<int>(amount+1,-1));
        return ans(amount,coins,0,mem);
    }
};
