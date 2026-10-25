# LeetCode 1254: Number of Closed Islands

## Problem
Given a 2D grid containing `0`s (land) and `1`s (water), find the number of closed islands.

A closed island is a group of connected land cells that is completely surrounded by water on all four sides and does not touch the grid boundary.

## Approach: Depth-First Search (DFS)

1. Traverse the boundary of the grid.
2. Use DFS to mark all land connected to the boundary as water.
3. Traverse the remaining inner cells.
4. Whenever an unvisited land cell (`0`) is found, increment the count and use DFS to mark the entire island.
5. Return the total number of closed islands.

## C++ Solution

```cpp
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        function<void(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n ||
                grid[r][c] == 1) {
                return;
            }

            grid[r][c] = 1;

            dfs(r - 1, c);
            dfs(r + 1, c);
            dfs(r, c - 1);
            dfs(r, c + 1);
        };

        for (int i = 0; i < m; i++) {
            dfs(i, 0);
            dfs(i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j);
            dfs(m - 1, j);
        }

        int count = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j);
                }
            }
        }

        return count;
    }
};
```

## Example

**Input:**
```text
grid = [[1,1,1,1,1,1,1,0],
        [1,0,0,0,0,1,1,0],
        [1,0,1,0,1,1,1,0],
        [1,0,0,0,0,1,0,1],
        [1,1,1,1,1,1,1,0]]
```

**Output:**
```text
2
```

## Complexity Analysis

- **Time Complexity:** `O(m × n)` — each cell is visited a constant number of times.
- **Space Complexity:** `O(m × n)` in the worst case due to recursive DFS calls.

Here, `m` is the number of rows and `n` is the number of columns.

## Topics
- Depth-First Search (DFS)
- Graph Traversal
- Matrix
- Flood Fill
- Connected Components

## Key Learning
An island touching the grid boundary cannot be closed. Remove all boundary-connected land first, then count the remaining connected components.

## Platform
LeetCode — Problem 1254

**Difficulty:** Medium
