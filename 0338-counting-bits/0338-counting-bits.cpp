class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0); // dp[i] = number of 1s in i

        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i & (i - 1)] + 1; // remove rightmost set bit
        }

        return dp;
    }
};