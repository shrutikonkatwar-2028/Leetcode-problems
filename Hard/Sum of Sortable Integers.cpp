
class Solution {
    bool isRotation(vector<int>& nums, vector<int>& sortedNums,
                    int start, int k) {
        vector<int> pattern(sortedNums.begin() + start,
                            sortedNums.begin() + start + k);

        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int value = nums[start + i % k];

            while (j > 0 && value != pattern[j]) {
                j = lps[j - 1];
            }

            if (value == pattern[j]) {
                j++;
            }

            if (j == k) {
                return true;
            }
        }

        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;

            for (int i = 0; i < n; i += k) {
                if (!isRotation(nums, sortedNums, i, k)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};
