# 🧹 Minimum Moves to Clean the Classroom

## 🔗 Problem

**LeetCode 3568 - Minimum Moves to Clean the Classroom**

You are given an `m × n` grid representing a classroom.

Each cell can contain:

* `'S'` → Starting position of the student
* `'L'` → Litter that must be collected
* `'R'` → Reset area that restores energy to maximum capacity
* `'X'` → Obstacle that cannot be crossed
* `'.'` → Empty cell

The student starts with maximum `energy`.

Each move in four directions costs **1 unit of energy**.

The goal is to collect **all litter** in the minimum number of moves.

If it is impossible to collect all litter, return `-1`.

---

## 💡 Approach

We use **Breadth-First Search (BFS) + Bitmasking**.

Since there are at most **10 litter cells**, we can represent the collected litter using a bitmask.

### State

Each BFS state contains:

```text
(x, y, mask, remainingEnergy)
```

Where:

* `(x, y)` → Current position
* `mask` → Represents collected litter
* `remainingEnergy` → Energy left

For example:

```text
mask = 101
```

means the 1st and 3rd litter items have been collected.

---

## 🔄 Algorithm

1. Find the starting position `'S'`.
2. Assign an index to every litter cell `'L'`.
3. Use a bitmask to track collected litter.
4. Start BFS from:

```text
(startX, startY, 0, energy)
```

5. For every adjacent cell:

   * Skip invalid positions.
   * Skip obstacles `'X'`.
   * Reduce energy by `1`.
   * If the cell contains `'L'`, update the bitmask.
   * If the cell contains `'R'`, restore energy to maximum.
6. Maintain the maximum energy reached for every:

```text
(x, y, mask)
```

7. If we collect all litter, return the current number of moves.
8. If BFS finishes without collecting everything, return `-1`.

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        vector<pair<int, int>> litter;

        // Find starting position and litter cells
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

        // Assign every litter cell an ID
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
            int size = q.size();

            while (size--) {
                auto [x, y, mask, e] = q.front();
                q.pop();

                // All litter collected
                if (mask == fullMask)
                    return steps;

                // Cannot move without energy
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    // Check boundaries
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    // Cannot pass through obstacles
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

                    // Skip if we already reached this state
                    // with equal or greater energy
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
```

---

## ⏱️ Complexity Analysis

Let:

* `m` = number of rows
* `n` = number of columns
* `L` = number of litter cells

Since `L ≤ 10`:

### Time Complexity

```text
O(m × n × 2^L × 4)
```

### Space Complexity

```text
O(m × n × 2^L)
```

---

## 🧪 Example

### Input

```text
classroom = ["S.", "XL"]
energy = 2
```

### Output

```text
2
```

### Explanation

The student follows:

```text
S → . → L
```

and collects all litter in **2 moves**.

---

## 🛠️ Concepts Used

* Breadth-First Search (BFS)
* Bitmasking
* Matrix Traversal
* State Space Search
* Dynamic Programming / State Optimization

---

⭐ **Key Idea:** For the same position and collected-litter state, keeping the path with more remaining energy is always better.
