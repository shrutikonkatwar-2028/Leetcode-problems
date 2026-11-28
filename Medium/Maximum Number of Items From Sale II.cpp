
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> cnt(n + 1, 0);

        // Count frequency of each factor
        for (auto &item : items) {
            cnt[item[0]]++;
        }

        // Find cheapest price
        int minPrice = INT_MAX;

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // Calculate number of free-item opportunities
        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += cnt[j];
            }
            if (gain[i] > 0) {
                gain[i]--;
            }
        }

        // Store useful purchases
        vector<pair<int, int>> candidates;

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            if (gain[factor] > 0 &&
                (long long)price < 2LL * minPrice) {
                candidates.push_back({price, gain[factor]});
            }
        }

        // Sort by price
        sort(candidates.begin(), candidates.end());

        long long ans = 0;
        long long remaining = budget;

        // Buy double-value copies first
        for (auto &[price, count] : candidates) {
            long long take = min((long long)count,
                                 remaining / price);

            ans += take * 2;
            remaining -= take * price;
        }

        // Spend remaining budget on cheapest item
        ans += remaining / minPrice;

        return (int)ans;
    }
};
