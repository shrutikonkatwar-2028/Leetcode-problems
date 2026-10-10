# LeetCode 2333: Minimum Sum of Squared Difference

## Problem Statement
Given two integer arrays `nums1` and `nums2` of equal length, and two integers `k1` and `k2`, minimize the sum of squared differences between corresponding elements.

You can increase or decrease elements of `nums1` at most `k1` times and elements of `nums2` at most `k2` times. Each operation changes an element by `1`.

Return the minimum possible sum of squared differences.

## Approach: Greedy + Frequency Counting

1. Calculate the absolute difference between corresponding elements of both arrays.
2. Store the frequency of each difference in a frequency array.
3. Combine the available operations as `k1 + k2`.
4. Start from the maximum difference and reduce it greedily by one.
5. Move the affected elements to the next lower difference.
6. Calculate the sum of the squares of all remaining differences.

## C++ Solution

```cpp
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        vector<int> difference(100001, 0);

        for (int i = 0; i < nums1.size(); i++) {
            difference[abs(nums1[i] - nums2[i])]++;
        }

        long long left = (long long)k1 + k2;

        for (int i = 100000; i > 0; i--) {
            if (difference[i] == 0) continue;

            long long count = difference[i];

            if (count <= left) {
                left -= count;
                difference[i - 1] += difference[i];
                difference[i] = 0;
            } else {
                difference[i] -= left;
                difference[i - 1] += left;
                left = 0;
                break;
            }
        }

        long long answer = 0;

        for (int i = 1; i <= 100000; i++) {
            answer += 1LL * difference[i] * i * i;
        }

        return answer;
    }
};
```

## Example

**Input:**
```text
nums1 = [1, 4, 10, 12]
nums2 = [5, 8, 6, 9]
k1 = 1
k2 = 1
```

**Output:**
```text
43
```

**Explanation:**

The initial absolute differences are `[4, 4, 4, 3]`.

Using two operations, the differences can become `[3, 4, 3, 3]`.

The minimum sum is:

`3² + 4² + 3² + 3² = 43`

## Complexity Analysis

- **Time Complexity:** `O(n + M)`
- **Space Complexity:** `O(M)`

Here, `n` is the length of the arrays and `M = 100000`, the maximum possible absolute difference.

## Key Concepts

- Greedy Algorithm
- Frequency Counting
- Arrays
- Optimization

## Conclusion

The greedy approach reduces the largest differences first. Frequency counting allows us to process equal differences together, making the solution efficient for large inputs.
