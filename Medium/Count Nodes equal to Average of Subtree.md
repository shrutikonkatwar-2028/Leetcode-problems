# 2265. Count Nodes Equal to Average of Subtree

## Problem Statement

Given the root of a binary tree, count the number of nodes where the value of the node is equal to the average of all values in its subtree.

The average is calculated using integer division, so the decimal part is discarded.

### Example 1

**Input:**

```text
root = [4,8,5,0,1,null,6]
```

**Output:**

```text
5
```

### Example 2

**Input:**

```text
root = [1]
```

**Output:**

```text
1
```

---

## Approach

For every node, we need two things from its subtree:

1. **Sum** of all node values
2. **Number of nodes**

We use **DFS (Depth First Search)** recursively.

For each node:

* Calculate the sum and count of the left subtree.
* Calculate the sum and count of the right subtree.
* Add the current node's value and count.
* Calculate:

```text
average = sum / count
```

* If the average is equal to the current node's value, increment the answer.
* Return the sum and count to the parent node.

---

## Algorithm

1. Initialize `ans = 0`.
2. Perform DFS on the binary tree.
3. For a `NULL` node, return `{0, 0}`.
4. Recursively find the sum and count of the left subtree.
5. Recursively find the sum and count of the right subtree.
6. Calculate the current subtree:

   ```text
   sum = leftSum + rightSum + root->val
   count = leftCount + rightCount + 1
   ```
7. Check:

   ```text
   sum / count == root->val
   ```
8. If true, increment `ans`.
9. Return `{sum, count}`.
10. Return `ans`.

---

## C++ Code

```cpp
class Solution {
public:
    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (sum / count == root->val)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```

---

## Complexity Analysis

### Time Complexity

```text
O(N)
```

Each node is visited exactly once.

### Space Complexity

```text
O(H)
```

where `H` is the height of the binary tree because of the recursive DFS stack.

---

## Key Points

* Use **DFS recursion**.
* Return both **subtree sum** and **subtree node count**.
* Integer division automatically performs the required floor operation.
* Every node is checked exactly once.
* Works for a single-node tree as well.

---

## Example Walkthrough

For:

```text
        4
       / \
      8   5
     / \   \
    0   1   6
```

For node `8`:

```text
sum = 8 + 0 + 1 = 9
count = 3
average = 9 / 3 = 3
```

Since:

```text
3 != 8
```

node `8` is not counted.

For node `5`:

```text
sum = 5 + 6 = 11
count = 2
average = 11 / 2 = 5
```

Since:

```text
5 == 5
```

node `5` is counted.

The final answer is:

```text
5
```

## Topic

**Binary Tree | DFS | Recursion | Tree Traversal**
