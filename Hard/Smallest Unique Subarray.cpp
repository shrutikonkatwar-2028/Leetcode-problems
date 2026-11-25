
class Solution {
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 911382323;

    vector<ll> h1, h2, p1, p2;

    bool check(int len) {
        unordered_map<unsigned long long, int> freq;

        int n = h1.size() - 1;

        for (int i = 0; i + len <= n; i++) {
            ll x = (h1[i + len] -
                    h1[i] * p1[len] % MOD1 + MOD1) % MOD1;

            ll y = (h2[i + len] -
                    h2[i] * p2[len] % MOD2 + MOD2) % MOD2;

            unsigned long long key =
                (static_cast<unsigned long long>(x) << 32) |
                static_cast<unsigned long long>(y);

            freq[key]++;
        }

        for (auto &it : freq) {
            if (it.second == 1)
                return true;
        }

        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;

            p1[i + 1] = p1[i] * BASE % MOD1;
            p2[i + 1] = p2[i] * BASE % MOD2;
        }

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
