# 3644. Maximum K to Sort a Permutation

## Problem
Find the maximum non-negative integer `k` such that the permutation can be sorted by swapping elements only when their bitwise AND equals `k`.

## Approach
Traverse the array and identify elements that are not in their correct positions (`nums[i] != i`). Calculate the bitwise AND of all these elements. If the array is already sorted, return `0`.

## Algorithm
1. Initialize `k = -1`.
2. Traverse the array.
3. If `nums[i] != i`, update `k = k & nums[i]`.
4. Return `0` if no elements are misplaced; otherwise, return `k`.

## Complexity
- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

## Language
C++
