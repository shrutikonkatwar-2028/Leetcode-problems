
# 2567. Minimum Score by Changing Two Elements

## Problem
We are given an integer array. We can change any two elements.

The score is calculated as:

Score = Maximum Difference + Minimum Difference

Find the minimum possible score after changing two elements.

## Approach
1. Sort the array in ascending order.
2. We can change two elements to make the minimum difference zero.
3. To minimize the maximum difference, consider three cases:
   - Change the first two elements.
   - Change the last two elements.
   - Change the first and last elements.
4. Calculate the remaining range in all three cases.
5. Return the minimum value.

## Example

Input:
nums = [1,4,7,8,5]

Output:
3

Explanation:
After sorting: [1,4,5,7,8]

Change two elements to get:
[6,6,5,7,8]

Minimum difference = 0
Maximum difference = 3

Answer = 3

## Complexity Analysis

Time Complexity: O(n log n)
- Sorting the array takes O(n log n).

Space Complexity: O(1)
- No extra array is used (excluding sorting implementation space).

## Concepts Used
- Arrays
- Sorting
- Greedy Algorithm
- Minimum and Maximum
