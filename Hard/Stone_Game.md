# 1872. Stone Game VIII

**LeetCode:** 1872
**Difficulty:** Hard
**Topics:** Array, Math, Dynamic Programming, Game Theory, Minimax, Prefix Sum

## Problem

Alice and Bob play a game with `n` stones arranged in a row.

On each turn, a player chooses `x > 1` stones from the left, removes them, and adds their sum to their score. A new stone with that sum is placed at the beginning.

The game continues until only one stone remains.

Alice tries to **maximize** the score difference, while Bob tries to **minimize** it.

Return:

`Alice's score - Bob's score`

when both players play optimally.

## Approach

The key observation is that after removing the first `i` stones, the new leftmost stone represents the **prefix sum** of those `i` stones.

Let:

`prefix[i] = stones[0] + stones[1] + ... + stones[i-1]`

We can define a DP state representing the best score difference for the remaining game.

The recurrence can be optimized using:

`dp[i] = max(prefix[j] - dp[j])` for `j > i`

Instead of checking every `j` for every `i`, maintain the maximum value while iterating from right to left.

This reduces the solution from **O(n²)** to **O(n)**.

## Complexity

* **Time:** `O(n)`
* **Space:** `O(n)`

## C++ Solution

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        long long best = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            best = max(best, prefix[i] - best);
        }

        return (int)best;
    }
};
```

## Example

### Input

```text
stones = [-1, 2, -3, 4, -5]
```

### Output

```text
5
```

Alice can remove the first four stones:

`-1 + 2 - 3 + 4 = 2`

Bob then removes the remaining two stones:

`2 + (-5) = -3`

Therefore:

`Alice - Bob = 2 - (-3) = 5`

## Key Takeaway

This problem is a **prefix-sum + optimized dynamic programming + game theory** problem.

The important idea is to avoid simulating every possible move. Instead, prefix sums represent the score gained when a certain number of stones are removed, and the DP keeps track of the optimal score difference.
