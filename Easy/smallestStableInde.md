# Smallest Stable Index I

## Problem Statement

Given an integer array `nums` and an integer `k`, the instability score of an index `i` is defined as:

```text
max(nums[0..i]) - min(nums[i..n-1])
```

An index is considered **stable** if its instability score is less than or equal to `k`.

The task is to return the **smallest stable index**. If no stable index exists, return `-1`.

---

## Approach

To efficiently calculate the instability score for every index, we use:

* **Prefix Maximum** to find the maximum element from index `0` to `i`.
* **Suffix Minimum** to find the minimum element from index `i` to `n - 1`.

### Steps

1. Create a `suffixMin` array.
2. Traverse from right to left and store the minimum value from each index to the end.
3. Traverse from left to right while maintaining the maximum value seen so far (`prefixMax`).
4. For every index, calculate:

```text
instability = prefixMax - suffixMin[i]
```

5. If the instability is less than or equal to `k`, return that index immediately.
6. If no stable index is found, return `-1`.

---

## Example

### Input

```text
nums = [5, 0, 1, 4]
k = 3
```

| Index | Prefix Maximum | Suffix Minimum | Instability |
| ----- | -------------- | -------------- | ----------- |
| 0     | 5              | 0              | 5           |
| 1     | 5              | 0              | 5           |
| 2     | 5              | 1              | 4           |
| 3     | 5              | 4              | 1           |

At index `3`:

```text
1 <= 3
```

Therefore, the answer is:

```text
3
```

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

---

## C++ Solution

```cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];

        // Calculate suffix minimum
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

        int prefixMax = nums[0];

        // Find the first stable index
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            long long instability =
                (long long)prefixMax - suffixMin[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};
```

---

## Key Concepts

* Array
* Prefix Maximum
* Suffix Minimum
* Simulation

---

**Problem:** LeetCode 3903 - Smallest Stable Index I
