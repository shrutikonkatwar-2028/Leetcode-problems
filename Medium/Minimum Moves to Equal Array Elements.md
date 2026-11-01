# 453. Minimum Moves to Equal Array Elements

## Problem Statement
Given an integer array `nums`, find the minimum number of moves
required to make all array elements equal.

In one move, we can increment `n - 1` elements of the array by 1.

## Example

Input:
nums = [1, 2, 3]

Output:
3

Explanation:
[1, 2, 3]
[2, 3, 3]
[3, 4, 3]
[4, 4, 4]

Minimum moves required = 3.

## Approach
Instead of incrementing n-1 elements, we can think of it as
decreasing one element by 1.

To make all elements equal with minimum moves:
1. Find the minimum element in the array.
2. Calculate the difference between every element and the minimum.
3. Add all differences to get the minimum number of moves.

## Formula

Minimum Moves = Sum of all elements - (n * Minimum Element)

## C++ Code

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = *min_element(nums.begin(), nums.end());

        int moves = 0;

        for (int num : nums) {
            moves += num - mini;
        }

        return moves;
    }
};
