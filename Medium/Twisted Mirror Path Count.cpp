class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int, int>>> right(
            m, vector<pair<int, int>>(n, {-1, -1})
        );

        vector<vector<pair<int, int>>> down(
            m, vector<pair<int, int>>(n, {-1, -1})
        );

        // Precompute mirror destinations
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (grid[i][j] == 0) {
                    right[i][j] = {i, j};
                    down[i][j] = {i, j};
                }
                else {
                    // Entering mirror from right
                    // Reflection sends robot down
                    if (i + 1 < m) {
                        right[i][j] = down[i + 1][j];
                    }

                    // Entering mirror from above
                    // Reflection sends robot right
                    if (j + 1 < n) {
                        down[i][j] = right[i][j + 1];
                    }
                }
            }
        }

        // DP table
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;

        // Count paths
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dp[i][j] == 0)
                    continue;

                // Move right
                if (j + 1 < n) {
                    auto [x, y] = right[i][j + 1];

                    if (x != -1 && y != -1) {
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }

                // Move down
                if (i + 1 < m) {
                    auto [x, y] = down[i + 1][j];

                    if (x != -1 && y != -1) {
                        dp[x][y] = (dp[x][y] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
