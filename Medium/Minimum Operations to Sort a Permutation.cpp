#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Find the shift that makes the array sorted.
        // Return -1 if no such rotation exists.
        auto getShift = [&](const vector<int>& arr) -> int {
            int pos = find(arr.begin(), arr.end(), 0) - arr.begin();

            for (int i = 0; i < n; ++i) {
                if (arr[(pos + i) % n] != i)
                    return -1;
            }

            return pos;
        };

        vector<int> rev(nums.rbegin(), nums.rend());

        int target0 = getShift(nums);
        int target1 = getShift(rev);

        if (target0 == -1 && target1 == -1)
            return -1;

        // State: (type, shift)
        // type 0 = rotation of nums
        // type 1 = rotation of reversed nums
        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        dist[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [type, shift] = q.front();
            q.pop();

            int d = dist[type][shift];

            // Check whether this state sorts the array.
            if ((type == 0 && shift == target0) ||
                (type == 1 && shift == target1)) {
                return d;
            }

            // Operation 1: Rotate left by one.
            int nextShift = (shift + 1) % n;

            if (dist[type][nextShift] == INT_MAX) {
                dist[type][nextShift] = d + 1;
                q.push({type, nextShift});
            }

            // Operation 2: Reverse the entire array.
            int nextType = 1 - type;
            nextShift = (n - shift) % n;

            if (dist[nextType][nextShift] == INT_MAX) {
                dist[nextType][nextShift] = d + 1;
                q.push({nextType, nextShift});
            }
        }

        return -1;
    }
};
