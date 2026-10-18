1569. Number of Ways to Reorder Array to Get Same BST
Problem
Given a permutation nums, insert its values in order into a Binary Search Tree (BST). Return the number of different reorderings that create the same BST as the original array, modulo 1,000,000,007.
The original ordering is included in the count by the recursive calculation, so subtract 1 before returning.
Approach: Divide and Conquer + Combinations
- The first value is the BST root.
- Values smaller than the root belong to the left subtree; larger values belong to the right subtree.
- Recursively count valid reorderings for the left and right subtrees.
- If the left subtree has L values and the right subtree has R values, their relative orders must stay valid, but the two sequences can be interleaved. There are C(L + R, L) ways to choose the positions occupied by the left-subtree values.
- Therefore:
  ways(nums) = C(L + R, L) * ways(left) * ways(right)
- Subtract one to exclude the original ordering.
Precompute binomial coefficients using Pascal's triangle:
C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
C++ Solution
class Solution {
private:
    static constexpr long long MOD = 1'000'000'007LL;
    vector<vector<long long>> choose;

    long long dfs(const vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long waysLeft = dfs(left);
        long long waysRight = dfs(right);
        long long interleave = choose[left.size() + right.size()][left.size()];

        return (((interleave * waysLeft) % MOD) * waysRight) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = static_cast<int>(nums.size());

        choose.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            choose[i][0] = choose[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
            }
        }

        return static_cast<int>((dfs(nums) - 1 + MOD) % MOD);
    }
};
Complexity
- Time: O(n^2) for Pascal's triangle, plus recursive partitioning (worst case O(n^2)).
- Space: O(n^2) for the combinations table, plus recursion and subtree vectors.
Examples
- nums = [2, 1, 3] → 1
- nums = [3, 4, 5, 1, 2] → 5
- nums = [1, 2, 3] → 0
Important
This is the LeetCode method signature: int numOfWays(vector<int>& nums). LeetCode supplies the required headers and using namespace std;.
