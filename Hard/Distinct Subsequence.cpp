class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<unsigned long long> dp(m + 1, 0);

        // Empty string t can always be formed once
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            // Traverse backwards to avoid overwriting values
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[m];
    }
};
