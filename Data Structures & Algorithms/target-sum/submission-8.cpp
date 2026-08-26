class Solution {
public:
   int ans(vector<int>& nums,int remaining,int index,vector<vector<int>>&mem){
    if(index==nums.size()){
        if(remaining==0)return 1;
    else return 0;
    }
    if(mem[index][remaining+1002] != -1)return mem[index][remaining+1002];
 return mem[index][remaining+1002]= ans(nums,remaining+nums[index],index+1,mem) + ans(nums,remaining-nums[index],index+1,mem);
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>mem(nums.size(),vector<int>(2005,-1));
        return ans(nums,target,0,mem);
    }
};
