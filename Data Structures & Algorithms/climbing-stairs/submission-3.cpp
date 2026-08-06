class Solution
{
public:
    int climbStairs(int n)
    {
        if(n==1)return 1;
        // dp[i] = number of distinct ways to reach the ith floor
        // dp[i] = dp[i-1]+dp[i-2]
        vector<int> dp(n + 1, 0);
        int prev = 1;
        int curr = 1;
        int next = 0;
        for (int i = 2; i <= n; i++)
        {
            next = prev + curr;
            prev = curr;
            curr = next;
        }
        return next;
    }
};