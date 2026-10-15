# 2913. Subarrays Distinct Element Sum of Squares I

## Problem
Find the sum of the squares of the distinct element counts of all non-empty contiguous subarrays.

## Approach
1. Iterate through every starting index.
2. Use an unordered set to track distinct elements.
3. Extend the subarray one element at a time.
4. Calculate the square of the set size and add it to the answer.

## Complexity
- Time: O(n²) average
- Space: O(n)

## Example
Input: `nums = [1, 2, 1]`

Output: `15`

Explanation: The distinct counts of the six subarrays are `1, 2, 2, 1, 2, 1`. Their squares sum to `15`.

## Language
C++
