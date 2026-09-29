# Check if There Is a Valid Parentheses String Path

## Problem

Given an `m × n` grid containing only `'('` and `')'`, determine whether there exists a path from the **top-left** cell to the **bottom-right** cell that forms a valid parentheses string.

The path can move only:

* Right
* Down

A parentheses string is valid when:

1. The number of `'('` and `')'` is equal.
2. For every prefix of the string, the number of `'('` is greater than or equal to the number of `')'`.

---

## Example

### Input

```text
grid = [
    ["(", "(", "("],
    [")", "(", ")"],
    ["(", "(", ")"],
    ["(", "(", ")"]
]
```

### Output

```text
true
```

### Explanation

One possible path forms:

```text
((()))
```

This is a valid parentheses string.

---

## Approach

We use **Dynamic Programming (DP)**.

For every cell, we store all possible `balance` values that can be obtained when reaching that cell.

### Balance

```text
balance = number of '(' - number of ')'
```

When we encounter:

```text
'(' → balance + 1
')' → balance - 1
```

For a valid parentheses string:

* Balance must never become negative.
* Final balance must be `0`.

We can reach every cell from either:

* The cell above it
* The cell to its left

Therefore, we combine the possible balances from both directions.

---

## Important Observation

The total number of characters in the path is:

```text
m + n - 1
```

A valid parentheses string must have an even length.

Therefore, if:

```text
(m + n - 1) % 2 != 0
```

we can immediately return `false`.

---

## Algorithm

1. Calculate `m` and `n`.
2. If the path length is odd, return `false`.
3. Create a DP table where each cell stores possible balance values.
4. Start from `(0,0)`.
5. If the starting cell is `')'`, return `false`.
6. For every cell:

   * Take balances from the top cell.
   * Take balances from the left cell.
   * Add `1` for `'('`.
   * Subtract `1` for `')'`.
   * Store only non-negative balances.
7. At the bottom-right cell, check whether balance `0` is possible.
8. Return the result.

---

## C++ Code

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string must have even length
        if ((m + n - 1) % 2 != 0)
            return false;

        vector<vector<unordered_set<int>>> dp(
            m, vector<unordered_set<int>>(n)
        );

        // Starting cell
        int startBalance = (grid[0][0] == '(') ? 1 : -1;

        if (startBalance < 0)
            return false;

        dp[0][0].insert(startBalance);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                // From top
                if (i > 0) {
                    for (int balance : dp[i - 1][j]) {
                        int newBalance = balance + change;

                        if (newBalance >= 0)
                            dp[i][j].insert(newBalance);
                    }
                }

                // From left
                if (j > 0) {
                    for (int balance : dp[i][j - 1]) {
                        int newBalance = balance + change;

                        if (newBalance >= 0)
                            dp[i][j].insert(newBalance);
                    }
                }
            }
        }

        // Valid string must end with balance 0
        return dp[m - 1][n - 1].count(0) > 0;
    }
};
```

---

## Complexity

Let `m` be the number of rows and `n` be the number of columns.

The maximum possible balance is `O(m + n)`.

### Time Complexity

```text
O(m × n × (m + n))
```

### Space Complexity

```text
O(m × n × (m + n))
```

---

## Key Concepts

* Dynamic Programming
* Matrix/Grid Traversal
* Parentheses Matching
* Balance Tracking
* State Management
* Set / Unordered Set

---

## Conclusion

The problem can be solved using dynamic programming by tracking all possible parentheses balances at every grid cell. We discard states where the balance becomes negative and finally check whether a balance of `0` can be achieved at the destination.
