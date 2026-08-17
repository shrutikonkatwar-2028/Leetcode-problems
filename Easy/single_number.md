# 136. Single Number

## Problem
Given a non-empty array of integers `nums`, every element appears twice except for one element. Find the element that appears only once.

The solution must have:
- Linear runtime complexity: `O(n)`
- Constant extra space: `O(1)`

## Approach

Use the **XOR (^)** bitwise operator.

Important XOR properties:

- `a ^ a = 0`
- `a ^ 0 = a`
- XOR is commutative and associative.

Therefore, when we XOR all elements, every number that appears twice cancels out, leaving only the number that appears once.

### Example

Input:

`[4,1,2,1,2]`

XOR operation:

`0 ^ 4 ^ 1 ^ 2 ^ 1 ^ 2 = 4`

Output:

`4`

## Algorithm

1. Initialize `ans = 0`.
2. Traverse every element in the array.
3. XOR the current element with `ans`.
4. Return `ans`.

## Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

## Language

C++
