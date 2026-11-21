
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int node) {
            int c = s[node] - 'a';
            int old = last[c];

            newParent[node] = (old == -1) ? parent[node] : old;

            last[c] = node;

            for (int child : adj[node]) {
                dfs(child);
            }

            last[c] = old;
        };

        dfs(0);

        vector<vector<int>> finalTree(n);

        for (int i = 1; i < n; i++) {
            finalTree[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<int(int)> calculate = [&](int node) {
            for (int child : finalTree[node]) {
                ans[node] += calculate(child);
            }
            return ans[node];
        };

        calculate(0);

        return ans;
    }
};
