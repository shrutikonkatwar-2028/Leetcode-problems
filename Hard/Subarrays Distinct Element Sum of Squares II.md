# LeetCode 2916: Subarrays Distinct Element Sum of Squares II

## Problem
Given an integer array `nums`, calculate the sum of the squares of the number of distinct elements in every non-empty contiguous subarray. Return the answer modulo `10^9 + 7`.

## Example

**Input**
```text
nums = [1, 2, 1]
```

**Output**
```text
15
```

**Explanation**

- `[1]` → 1² = 1
- `[2]` → 1² = 1
- `[1]` → 1² = 1
- `[1, 2]` → 2² = 4
- `[2, 1]` → 2² = 4
- `[1, 2, 1]` → 2² = 4

Total = 15.

## Approach: Segment Tree + Lazy Propagation

1. Maintain the last occurrence of each element.
2. For each index `i`, find the previous occurrence of `nums[i]`.
3. Increase the distinct counts for the range `[previous occurrence + 1, i]`.
4. Maintain both the sum and the sum of squares in the segment tree.
5. Add the root's sum of squares to the final answer at each step.
6. Return the result modulo `1,000,000,007`.

## Formula

When each value in a segment increases by `v`:

`(x + v)² = x² + 2vx + v²`

This allows the segment tree to update the sum of squares efficiently.

## Complexity Analysis

- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

Here, `n` is the length of the input array.

## Concepts Learned

- Arrays and subarrays
- Hashing and last occurrence tracking
- Segment trees
- Lazy propagation
- Modular arithmetic
- Range updates

## Platform

LeetCode — Problem 2916

**Difficulty:** Hard

**Language:** C++
