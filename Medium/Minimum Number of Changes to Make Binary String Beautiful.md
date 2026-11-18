
# 2914. Minimum Number of Changes to Make Binary String Beautiful

## Problem
Given an even-length binary string, find the minimum number of changes required to make it beautiful.

A beautiful string can be divided into groups of even length, where each group contains only 0s or only 1s.

## Approach
- Divide the string into pairs of two characters.
- Check each pair.
- If both characters are the same, no changes are needed.
- If both characters are different, one change is required.
- Count all such changes and return the answer.

## Example

Input: s = "1001"

Pairs:
- "10" -> 1 change
- "01" -> 1 change

Output: 2

## Complexity Analysis
- Time Complexity: O(n)
- Space Complexity: O(1)

## Key Concept
Greedy Approach – Make every pair contain identical characters using the minimum number of changes.
