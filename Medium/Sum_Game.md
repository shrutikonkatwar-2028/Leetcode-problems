Sum Game

Problem

Given a string num containing digits and '?', Alice and Bob take turns replacing a '?' with a digit from 0 to 9.

Alice wins if the sum of digits in the left half is different from the sum in the right half. Otherwise, Bob wins.

Approach

Count:

leftSum = sum of known digits in the left half

rightSum = sum of known digits in the right half

leftQ = number of ? in the left half

rightQ = number of ? in the right half

Key Observation

If the total number of question marks is odd, Alice can always force a win.

Otherwise, Bob can make the two halves equal only when:

leftSum - rightSum = 9 * (rightQ - leftQ) / 2

Therefore, Alice wins when this equality does not hold.

Complexity

Time: O(n)

Space: O(1)

C++ Code

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        if ((leftQ + rightQ) % 2 == 1)
            return true;

        return leftSum - rightSum != 9 * (rightQ - leftQ) / 2;
    }
};

Tags

Greedy Math Game Theory String
