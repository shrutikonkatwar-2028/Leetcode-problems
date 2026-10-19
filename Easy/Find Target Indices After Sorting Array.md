# LeetCode 2089 – Find Target Indices After Sorting Array

## Problem
Given an integer array `nums` and an integer `target`, return the indices where `nums[i] == target` after sorting the array in non-decreasing order.

## Approach
We can solve this problem without sorting the array.

1. Count the elements smaller than `target`.
2. Count the occurrences of `target`.
3. Starting from the count of smaller elements, add consecutive indices to the result.

## C++ Solution

```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int equal = 0;

        for (int num : nums) {
            if (num < target) {
                smaller++;
            } else if (num == target) {
                equal++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < equal; i++) {
            ans.push_back(smaller + i);
        }

        return ans;
    }
};
```

## Example

**Input**
```text
nums = [1,2,5,2,3]
target = 2
```

**Sorted Array**
```text
[1,2,2,3,5]
```

**Output**
```text
[1,2]
```

## Complexity Analysis

- **Time Complexity:** `O(n)` — We traverse the array once to count elements.
- **Auxiliary Space Complexity:** `O(1)` — Only a constant number of variables are used, excluding the output vector.

## Concepts Used
- Arrays
- Counting
- Linear Traversal
- Sorting Logic
- C++ Vectors

**Platform:** LeetCode  
**Problem Number:** 2089  
**Difficulty:** Easy
