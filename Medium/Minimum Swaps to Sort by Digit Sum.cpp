
class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for (int x : nums) {
            arr.push_back({digitSum(x), x});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> target;
        for (int i = 0; i < n; i++) {
            target[arr[i].second] = i;
        }

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = target[nums[i]];
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || p[i] == i)
                continue;

            int size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = p[j];
                size++;
            }

            swaps += size - 1;
        }

        return swaps;
    }
};
