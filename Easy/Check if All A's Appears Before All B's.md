
# 2124. Check if All A's Appears Before All B's

## Problem
Given a string containing only 'a' and 'b', check whether all 'a' characters appear before all 'b' characters.

Return true if the condition is satisfied, otherwise return false.

## Approach
- Traverse the string using a loop.
- Check every adjacent pair of characters.
- If 'b' appears before 'a' (substring "ba"), return false.
- If no "ba" is found, return true.

## Example

Input: s = "aaabbb"

Output: true

Input: s = "abab"

Output: false

## Time Complexity
O(N) - We traverse the string once.

## Space Complexity
O(1) - No extra space is used.
