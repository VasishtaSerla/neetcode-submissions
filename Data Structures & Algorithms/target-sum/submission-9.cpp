class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int x : nums) {
            total_sum += x;
        }

        // Validity checks
        if (abs(target) > total_sum || (total_sum + target) % 2 != 0) {
            return 0;
        }

        int subset_sum = (total_sum + target) / 2;
        vector<int> dp(subset_sum + 1, 0);
        
        // Base case: 1 way to get sum 0 (empty subset)
        dp[0] = 1;

        for (int num : nums) {
            // Traverse backwards so each element is used at most once
            for (int j = subset_sum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }

        return dp[subset_sum];
    }
};