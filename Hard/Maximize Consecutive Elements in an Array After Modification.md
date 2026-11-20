
# 3041. Maximize Consecutive Elements in an Array After Modification

## Problem
Given an array of positive integers, we can increase any element by at most 1.

Find the maximum number of elements that can be selected to form consecutive integers.

## Approach
1. Sort the array.
2. Use Dynamic Programming with a Hash Map.
3. dp[x] stores the maximum length of consecutive elements ending at x.
4. Each element can remain x or become x+1.
5. Update the maximum answer.

## Example

Input:
nums = [2,1,5,1,1]

Output:
3

Explanation:
After modification, we can select [1,2,3].

## Complexity Analysis

Time Complexity: O(n log n)
- Sorting takes O(n log n).
- DP traversal takes O(n) average.

Space Complexity: O(n)
- Hash Map stores DP states.
