/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }

        // Swap left and right subtrees
        swap(root->left, root->right);

        // Recursively invert both subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
