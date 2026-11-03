3736. Minimum Moves to Equal Array Elements III

Problem

Given an integer array "nums", in one move we can increase any element by 1.

Return the minimum number of moves required to make all elements equal.

Approach

- Find the maximum element in the array.
- Increase every smaller element until it becomes equal to the maximum.
- Add the required increments to calculate the total minimum moves.

We choose the maximum element because we can only increase elements, not decrease them.

C++ Code

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        int moves = 0;

        for (int i = 0; i < nums.size(); i++) {
            moves += maxi - nums[i];
        }

        return moves;
    }
};

Example

Input:

nums = [2,1,3]

Output:

3

Explanation:

- Increase 2 to 3: 1 move
- Increase 1 to 3: 2 moves
- Total = 3 moves

Complexity

- Time Complexity: O(n)
- Space Complexity: O(1)

Key Concept

The minimum moves required are equal to the sum of the differences between the maximum element and every element in the array.
