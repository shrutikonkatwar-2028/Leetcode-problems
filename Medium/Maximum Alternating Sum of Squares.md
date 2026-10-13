# 3727. Maximum Alternating Sum of Squares

## Problem Statement

Given an integer array `nums`, rearrange its elements in any order to maximize the alternating score.

The score is calculated as:

`arr[0]² - arr[1]² + arr[2]² - arr[3]² + ...`

Return the maximum possible alternating score.

## Approach: Greedy + Sorting

1. Square every element because the original sign does not affect its square.
2. Sort the squared values in ascending order.
3. Subtract the smallest `ceil(n/2)` squared values.
4. Add the largest `floor(n/2)` squared values.
5. Return the final score.

### Example

**Input:**
```text
nums = [1, 2, 3]
```

**Squared values:** `[1, 4, 9]`

**Calculation:**
```text
9 + 4 - 1 = 12
```

**Output:**
```text
12
```

## C++ Solution

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int num : nums) {
            squares.push_back(1LL * num * num);
        }

        sort(squares.begin(), squares.end());

        long long ans = 0;
        int n = squares.size();

        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                ans -= squares[i];
            } else {
                ans += squares[i];
            }
        }

        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(n log n)` due to sorting.
- **Space Complexity:** `O(n)` for storing squared values.

## Key Concepts

- Arrays
- Greedy Algorithm
- Sorting
- Mathematical Optimization

## Conclusion

Sorting the squared values allows us to subtract the smallest values and add the largest values, maximizing the alternating score efficiently.
