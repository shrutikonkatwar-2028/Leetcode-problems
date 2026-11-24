
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long lcm = 1;
            int g = 0;

            for (int j = i; j < n; j++) {
                prod *= nums[j];

                g = gcd(g, nums[j]);

                lcm = lcm / gcd(lcm, (long long)nums[j]) * nums[j];

                if (prod == lcm * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
