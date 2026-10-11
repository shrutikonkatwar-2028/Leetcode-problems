# 2778. Sum of Squares of Special Elements

## Problem Statement
Given a 1-indexed integer array `nums` of length `n`, an element is called special if its index divides `n`.

Return the sum of squares of all special elements.

## Approach
1. Find the length of the array `n`.
2. Iterate through indices from `1` to `n`.
3. Check if `n % i == 0`.
4. If true, add the square of `nums[i - 1]` to the sum.
5. Return the final sum.

## Code (C++)

```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                sum += nums[i - 1] * nums[i - 1];
            }
        }

        return sum;
    }
};
```

## Example

**Input:**
```text
nums = [1, 2, 3, 4]
```

**Output:**
```text
21
```

**Explanation:**

The special indices are `1`, `2`, and `4`.

Sum = `1² + 2² + 4² = 21`

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

## Topics
- Array
- Enumeration
- Mathematics

## Platform
LeetCode — Problem 2778

