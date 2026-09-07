class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        
        vector<long long> last(26, 0);
        long long dp = 1; // Empty subsequence
        
        for (char c : s) {
            int idx = c - 'a';
            
            long long newDp = (2 * dp % MOD - last[idx] + MOD) % MOD;
            
            last[idx] = dp;
            dp = newDp;
        }
        
        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};
