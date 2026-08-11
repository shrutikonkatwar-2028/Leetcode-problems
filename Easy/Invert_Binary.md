# 226. Invert Binary Tree

**LeetCode:** 226
**Difficulty:** Easy
**Language:** C++

## Problem

Given the root of a binary tree, invert the tree and return its root.

Inverting a binary tree means swapping the left and right child of every node.

### Example

**Input:**

```text
[4,2,7,1,3,6,9]
```

**Output:**

```text
[4,7,2,9,6,3,1]
```

### Approach

We use **recursion (DFS)**.

For every node:

1. If the node is `nullptr`, return.
2. Swap its left and right children.
3. Recursively invert the left subtree.
4. Recursively invert the right subtree.
5. Return the root.

### Example

Before inversion:

```text
        4
       / \
      2   7
     / \ / \
    1  3 6  9
```

After inversion:

```text
        4
       / \
      7   2
     / \ / \
    9  6 3  1
```

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(h)`

where:

* `n` = number of nodes
* `h` = height of the tree

The `O(h)` space is used by the recursion stack.

## Key Concept

The important operation is simply:

```cpp
swap(root->left, root->right);
```

Then we perform the same operation recursively for both subtrees.

## Solution

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
```
