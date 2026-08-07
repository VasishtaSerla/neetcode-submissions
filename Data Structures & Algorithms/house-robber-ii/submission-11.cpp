class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int ans1,ans2;
        int dp1[nums.size()],dp2[nums.size()];
        dp1[0] = 0;
        dp1[1] = max(nums[1],0);
        for(int i = 2; i<nums.size(); i++){
            dp1[i] = max(dp1[i-2]+nums[i],dp1[i-1]);
        }
        ans1 = dp1[nums.size()-1];

        //included
             dp2[0] = nums[0];
        dp2[1] = max(nums[1],dp2[0]);
        for(int i = 2; i<nums.size()-1; i++){
            dp2[i] = max(dp2[i-2]+nums[i],dp2[i-1]);
        }
        dp2[nums.size()-1] = dp2[nums.size()-2];
        ans2 = dp2[nums.size()-1];  
        return max(ans1,ans2);
    }
};
