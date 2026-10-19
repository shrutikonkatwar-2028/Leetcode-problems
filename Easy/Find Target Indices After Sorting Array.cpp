
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int equal = 0;

        for (int num : nums) {
            if (num < target) {
                smaller++;
            } else if (num == target) {
                equal++;
            }
        }

        vector<int> ans;

        for (int i = 0; i < equal; i++) {
            ans.push_back(smaller + i);
        }

        return ans;
    }
};
