3841. Palindromic Path Queries in a Tree
Problem
Given a tree whose nodes contain lowercase letters, process queries of two types:
- update u c: change the character at node u to c.
- query u v: determine whether the characters on the unique path from u to v can be rearranged into a palindrome.
Return one boolean result for every query operation.
Approach: Heavy-Light Decomposition + Segment Tree + Bitmask
1. Represent character parity using a bitmask
Each lowercase character maps to one of 26 bits:
1 << (c - 'a')
The XOR of these masks across a path tells us which characters occur an odd number of times.

A string can be rearranged into a palindrome if and only if at most one character has an odd frequency. Therefore, the path is valid when its XOR mask is zero or has exactly one set bit:
mask == 0 || (mask & (mask - 1)) == 0
2. Heavy-Light Decomposition (HLD)
HLD divides each tree path into O(log n) contiguous segments in an array.
- dfs1 computes each node's parent, depth, subtree size, and heavy child.
- dfs2 assigns each node a chain head and a position in the flattened array.
- A path query jumps between chain heads and combines segment results with XOR.
3. Segment tree
The segment tree stores the character bitmask at each flattened node position.
- Point update: replace the mask when a node's character changes.
- Range query: return the XOR mask for a segment.
- Path query: XOR the masks of all HLD segments on the path.
Complexity
- Preprocessing: O(n)
- Each update: O(log n)
- Each path query: O(log^2 n)
- Space: O(n)
The solution supports up to 5 * 10^4 nodes and queries.
C++ (LeetCode)
The implementation is in [`solution.cpp`](solution.cpp). It uses the LeetCode-style method signature:
vector<bool> palindromePath(
    int n,
    vector<vector<int>>& edges,
    string s,
    vector<string>& queries
);
Example
Input:
n = 3
edges = [[0,1],[1,2]]
s = "aac"
queries = ["query 0 2","update 1 b","query 0 2"]
Output:
[true,false]
Explanation:
- Initially, path 0 -> 1 -> 2 contains a, a, c. Only c has odd frequency, so the answer is true.
- After updating node 1 to b, the path contains a, b, c. Three characters have odd frequency, so the answer is false.
