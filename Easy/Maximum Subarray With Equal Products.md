
# 3411. Maximum Subarray With Equal Products

## Problem
Given an array of positive integers, find the length of the longest subarray where:

Product of elements = LCM of elements * GCD of elements.

## Approach: Brute Force + GCD + LCM

1. Traverse all possible starting indices.
2. Initialize product, GCD and LCM.
3. Extend the subarray one element at a time.
4. Update product using multiplication.
5. Update GCD using the gcd() function.
6. Update LCM using the formula:

   LCM(a,b) = (LCM(a,b) / GCD(LCM(a,b))) * b

7. Check whether product == LCM * GCD.
8. If true, update the maximum length.

## Complexity Analysis

- Time Complexity: O(n² log M)
- Space Complexity: O(1)

Here, n is the size of the array and M is the maximum element.

## Example 1

Input:
nums = [1,2,1,2,1,1,1]

Output:
5

## Example 2

Input:
nums = [2,3,4,5,6]

Output:
3

## Example 3

Input:
nums = [1,2,3,1,4,5,1]

Output:
5
