# 9. Palindrome Number

## Problem
Given an integer `x`, return `true` if `x` is a palindrome, otherwise return `false`.

A palindrome number reads the same forward and backward.

## Examples

### Example 1
Input:
`121`

Output:
`true`

### Example 2
Input:
`-121`

Output:
`false`

### Example 3
Input:
`10`

Output:
`false`

## Approach

1. If `x` is negative, return `false`.
2. Store the original number.
3. Reverse the digits using modulo `% 10`.
4. Compare the reversed number with the original number.
5. If both are equal, the number is a palindrome.

## Complexity

- Time Complexity: `O(log x)`
- Space Complexity: `O(1)`

## Language

C++
