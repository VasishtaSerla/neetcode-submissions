#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;

        // dp[i] stores number of ways to decode substring s[i...n-1]
        // Size is n + 1 to easily handle base case dp[n] = 1
        vector<int> dp(n + 1, 0);

        // Base case: reaching the end of the string represents 1 valid path
        dp[n] = 1;

        // Fill table backwards from n - 1 down to 0
        for (int i = n - 1; i >= 0; i--) {
            // Case 1: Leading zero cannot be decoded
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                // Choice 1: Take 1 digit
                dp[i] = dp[i + 1];

                // Choice 2: Take 2 digits (if valid <= 26)
                if (i + 1 < n) {
                    int twoDigitVal = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (twoDigitVal <= 26) {
                        dp[i] += dp[i + 2];
                    }
                }
            }
        }

        // The final answer for the full string s[0...n-1] is at dp[0]
        return dp[0];
    }
};