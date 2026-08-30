class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minPos = 0, maxPos = 0;

        // Find positions of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minPos])
                minPos = i;

            if (nums[i] > nums[maxPos])
                maxPos = i;
        }

        // Put minPos before maxPos
        if (minPos > maxPos)
            swap(minPos, maxPos);

        // Case 1: Remove both from the front
        int front = maxPos + 1;

        // Case 2: Remove both from the back
        int back = n - minPos;

        // Case 3: Remove min from front and max from back
        int both = (minPos + 1) + (n - maxPos);

        return min({front, back, both});
    }
};
