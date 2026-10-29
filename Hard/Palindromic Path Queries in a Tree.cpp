#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, subtreeSize, heavy, head, pos;
    vector<int> segTree;
    int timer, base;

    void dfs1(int u, int p) {
        parent[u] = p;
        subtreeSize[u] = 1;
        heavy[u] = -1;

        int largest = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            dfs1(v, u);

            subtreeSize[u] += subtreeSize[v];

            if (subtreeSize[v] > largest) {
                largest = subtreeSize[v];
                heavy[u] = v;
            }
        }
    }

    void dfs2(int u, int h, string& s) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1) {
            dfs2(heavy[u], h, s);
        }

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;

            dfs2(v, v, s);
        }
    }

    void build(string& s) {
        base = 1;

        while (base < s.size())
            base <<= 1;

        segTree.assign(2 * base, 0);

        for (int i = 0; i < s.size(); i++) {
            segTree[base + pos[i]] = 1 << (s[i] - 'a');
        }

        for (int i = base - 1; i >= 1; i--) {
            segTree[i] =
                segTree[2 * i] ^ segTree[2 * i + 1];
        }
    }

    void update(int index, int value) {
        int p = base + index;
        segTree[p] = value;

        p >>= 1;

        while (p >= 1) {
            segTree[p] =
                segTree[2 * p] ^ segTree[2 * p + 1];

            if (p == 1) break;

            p >>= 1;
        }
    }

    int rangeQuery(int l, int r) {
        int result = 0;

        l += base;
        r += base;

        while (l <= r) {
            if (l & 1)
                result ^= segTree[l++];

            if (!(r & 1))
                result ^= segTree[r--];

            l >>= 1;
            r >>= 1;
        }

        return result;
    }

    int pathQuery(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= rangeQuery(pos[head[u]], pos[u]);

            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= rangeQuery(pos[u], pos[v]);

        return mask;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, vector<int>());

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        subtreeSize.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);

        timer = 0;

        dfs1(0, -1);
        dfs2(0, 0, s);
        build(s);

        vector<bool> answer;

        for (string& query : queries) {
            stringstream ss(query);

            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;

                ss >> u >> c;

                s[u] = c;

                update(pos[u], 1 << (c - 'a'));
            }
            else {
                int u, v;

                ss >> u >> v;

                int mask = pathQuery(u, v);

                bool possible =
                    (mask == 0 || (mask & (mask - 1)) == 0);

                answer.push_back(possible);
            }
        }

        return answer;
    }
};
