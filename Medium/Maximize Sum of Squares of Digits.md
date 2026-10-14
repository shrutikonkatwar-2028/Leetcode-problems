# LeetCode 3723: Maximize Sum of Squares of Digits

## Problem Statement
Given two positive integers `num` and `sum`, construct a number with exactly `num` digits whose digit sum equals `sum`. Maximize the sum of squares of its digits. If multiple numbers achieve the maximum score, return the largest number. If no valid number exists, return an empty string.

## Approach: Greedy
1. If `sum > 9 * num`, return an empty string because the digits cannot add up to the required sum.
2. Start from the leftmost position.
3. Place the largest possible digit, `min(9, sum)`.
4. Subtract that digit from `sum`.
5. Repeat until `num` digits have been placed.

## Example
**Input:** `num = 2, sum = 17`

**Output:** `"98"`

Explanation:
- First digit: 9; remaining sum = 8.
- Second digit: 8; remaining sum = 0.
- The digit sum is 17, and the score is \(9^2 + 8^2 = 145\).

## Complexity Analysis
- **Time Complexity:** O(num)
- **Space Complexity:** O(num), for the returned string.

## Language
C++17

## Key Concept
Greedy Algorithm — prioritize larger digits to maximize the sum of squared digits. When scores tie, choosing larger digits on the left produces the maximum integer.
