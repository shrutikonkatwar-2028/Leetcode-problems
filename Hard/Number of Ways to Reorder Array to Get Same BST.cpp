
    
  
class Solution {
private:
    static constexpr long long MOD = 1'000'000'007LL;
    vector<vector<long long>> choose;

    long long dfs(const vector<int>& nums, int mod) {
        if (nums.size() <= 2) return 1;

        vector<int> left, right;
        left.reserve(nums.size());
        right.reserve(nums.size());

        int root = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long waysLeft = dfs(left, mod);
        long long waysRight = dfs(right, mod);
        long long interleave = choose[left.size() + right.size()][left.size()];

        return (((interleave * waysLeft) % mod) * waysRight) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        const int mod = 1'000'000'007;

        choose.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            choose[i][0] = choose[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % mod;
            }
        }

        return static_cast<int>((dfs(nums, mod) - 1 + mod) % mod);
    }
};
