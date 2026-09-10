class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        // Get sum and count from left subtree
        auto left = dfs(root->left);

        // Get sum and count from right subtree
        auto right = dfs(root->right);

        // Current subtree sum and count
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        // Average is rounded down
        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
