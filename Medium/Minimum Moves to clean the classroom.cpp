class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        vector<pair<int, int>> litter;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } 
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        int fullMask = (1 << k) - 1;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        // best[x][y][mask] = maximum remaining energy
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );

        queue<array<int, 4>> q;
        q.push({sx, sy, 0, energy});

        best[sx][sy][0] = energy;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [x, y, mask, e] = q.front();
                q.pop();

                if (mask == fullMask)
                    return steps;

                // If energy is 0, cannot move further
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if (classroom[nx][ny] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // Collect litter
                    if (id[nx][ny] != -1) {
                        newMask |= (1 << id[nx][ny]);
                    }

                    // Reset energy
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    // Keep only better energy states
                    if (best[nx][ny][newMask] >= newEnergy)
                        continue;

                    best[nx][ny][newMask] = newEnergy;
                    q.push({nx, ny, newMask, newEnergy});
                }
            }

            steps++;
        }

        return -1;
    }
};
