# 3331. Find Subtree Sizes After Changes

**Difficulty:** Medium

## Approach: DFS (Depth First Search)

### Explanation
1. First, create the original tree using the parent array.
2. Perform DFS starting from root node 0.
3. Maintain an array `last[26]` to track the nearest ancestor having the same character.
4. If a matching ancestor exists, make it the new parent of the current node.
5. Otherwise, keep the original parent.
6. Construct the final tree using the updated parent array.
7. Perform another DFS to calculate the subtree sizes.
8. Store the subtree size of every node in the answer array.

## Complexity Analysis

- **Time Complexity:** O(N)
- **Space Complexity:** O(N)

## Example

**Input:**
```text
parent = [-1,0,0,1,1,1]
s = "abaabc"
```

**Output:**
```text
[6,3,1,1,1,1]
```

## Key Concepts
- Tree
- DFS
- Recursion
- Parent Array
- Subtree Size Calculation
