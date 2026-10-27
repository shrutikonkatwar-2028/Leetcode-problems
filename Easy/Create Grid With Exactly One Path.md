# 3963. Create Grid With Exactly One Path

## Problem
Construct an `m x n` grid using `'.'` and `'#'` such that there is exactly one valid path from the top-left cell to the bottom-right cell.

## Approach
Create a grid filled with obstacles (`'#'`).

1. Make every cell in the first row free (`'.'`).
2. Make every cell in the last column free (`'.'`).
3. Return the grid.

This creates a single path that moves right along the first row and then down along the last column.

## C++ Solution

```cpp
class Solution {
public:
    vector<string> findUniquePath(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        for (int j = 0; j < n; j++) {
            grid[0][j] = '.';
        }

        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};
```

## Example

Input:
```text
m = 2, n = 3
```

Output:
```text
["..#", "#.."]
```

## Complexity
- Time Complexity: `O(m * n)`
- Space Complexity: `O(m * n)`

## Key Concept
Constructive Algorithm — create a valid output directly instead of searching for one.
