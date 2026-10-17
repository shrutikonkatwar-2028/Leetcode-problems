# 3551. Minimum Swaps to Sort by Digit Sum

## Problem
Sort an array by increasing digit sum. If two numbers have the same digit sum, sort them by their numeric value. Return the minimum number of swaps required.

## Approach
1. Calculate the digit sum of each number.
2. Sort pairs `(digitSum, number)`.
3. Map each number to its target index.
4. Build a permutation representing the target positions.
5. Detect cycles. A cycle of length `k` requires `k - 1` swaps.

## Example

**Input:** `nums = [18, 43, 34, 16]`

Digit sums:
- 18 → 9
- 43 → 7
- 34 → 7
- 16 → 7

Sorted array: `[16, 34, 43, 18]`

**Output:** `2`

## Complexity
- Time: `O(n log n)`
- Space: `O(n)`

## Key Concept
The minimum swaps needed for a permutation equal the sum of `cycle length - 1` for all nontrivial cycles.
