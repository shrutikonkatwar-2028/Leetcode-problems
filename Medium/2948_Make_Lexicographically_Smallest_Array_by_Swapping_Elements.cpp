#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Store value and its original index
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int start = 0;

        while (start < n) {
            int end = start;

            // Find the connected component.
            // Consecutive values can belong to the same group
            // if their difference is <= limit.
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Collect original indices of this component
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            // Original indices should be sorted so that
            // the smallest values go to the smallest positions.
            sort(indices.begin(), indices.end());

            // Values in arr[start...end] are already sorted.
            for (int i = start; i <= end; i++) {
                nums[indices[i - start]] = arr[i].first;
            }

            start = end + 1;
        }

        return nums;
    }
};
