# 3882. Minimum XOR Path in a Grid

## Problem
Given an `m x n` integer grid, find the minimum possible XOR value among all paths from the top-left cell `(0, 0)` to the bottom-right cell `(m - 1, n - 1)`.

You can move only:
- Right
- Down

The path cost is the bitwise XOR of all cell values along the path, including the starting and ending cells.

## Approach: Dynamic Programming + Bit Manipulation

We use a 3D DP array:

`dp[i][j][x]`

It represents whether it is possible to reach cell `(i, j)` with XOR value `x`.

Since every grid value is at most `1023`, the XOR value is also within the range `0` to `1023`.

### Transitions

For each cell, we can arrive from:

- The top cell `(i - 1, j)`
- The left cell `(i, j - 1)`

If the previous XOR value is `x`, the new XOR value becomes:

`x ^ grid[i][j]`

We mark the new XOR value as reachable.

Finally, we find the smallest reachable XOR value at the bottom-right cell.

## C++ Solution

```cpp
class Solution {
public:
    int minPathXor(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(
                n, vector<bool>(1024, false)
            )
        );

        // Starting cell
        dp[0][0][grid[0][0]] = true;

        // Traverse the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // From top
                if (i > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i - 1][j][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }

                // From left
                if (j > 0) {
                    for (int x = 0; x < 1024; x++) {
                        if (dp[i][j - 1][x]) {
                            dp[i][j][x ^ grid[i][j]] = true;
                        }
                    }
                }
            }
        }

        // Find minimum XOR at destination
        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};
```

## Example

### Input

```text
grid = [[1,2],
        [3,4]]
```

### Possible Paths

Path 1: Right → Down

`1 ^ 2 ^ 4 = 7`

Path 2: Down → Right

`1 ^ 3 ^ 4 = 6`

### Output

```text
6
```

## Complexity

- **Time Complexity:** `O(m * n * 1024)`
- **Space Complexity:** `O(m * n * 1024)`

## Key Concepts

- Dynamic Programming
- Bit Manipulation
- Bitwise XOR
- 3D DP

## Important Note

Unlike minimum sum path problems, we cannot simply select the minimum XOR from the top or left cell.

We must track all possible XOR values at each cell because XOR does not preserve the ordering of values.
