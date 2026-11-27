

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int freeItems = 0;

            // Count free items obtained by buying this item
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeItems++;
                }
            }

            vector<int> curr = dp;

            // Buy the first copy and receive free items
            for (int b = price; b <= budget; b++) {
                curr[b] = max(curr[b],
                              dp[b - price] + 1 + freeItems);
            }

            // Buy additional copies of the same item
            for (int b = price; b <= budget; b++) {
                curr[b] = max(curr[b],
                              curr[b - price] + 1);
            }

            dp = curr;
        }

        return dp[budget];
    }
};
