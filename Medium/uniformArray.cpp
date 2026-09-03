class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        // Find smallest odd and smallest even number
        for (int x : nums1) {
            if (x % 2 == 0)
                minEven = min(minEven, x);
            else
                minOdd = min(minOdd, x);
        }

        // Try making all elements EVEN
        bool allEven = true;

        for (int x : nums1) {
            if (x % 2 != 0) {
                // Odd number needs subtraction with a smaller odd number
                if (minOdd == INT_MAX || minOdd >= x) {
                    allEven = false;
                    break;
                }
            }
        }

        // Try making all elements ODD
        bool allOdd = true;

        for (int x : nums1) {
            if (x % 2 == 0) {
                // Even - Odd = Odd
                if (minOdd == INT_MAX || minOdd >= x) {
                    allOdd = false;
                    break;
                }
            } else {
                // Odd numbers can remain unchanged
            }
        }

        return allEven || allOdd;
    }
};
