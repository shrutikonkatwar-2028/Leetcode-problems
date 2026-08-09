#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
        int m = image.size();
        int n = image[0].size();

        // Check boundaries
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Only fill pixels having the original color
        if (image[r][c] != oldColor)
            return;

        image[r][c] = newColor;

        // Move up
        dfs(image, r - 1, c, oldColor, newColor);

        // Move down
        dfs(image, r + 1, c, oldColor, newColor);

        // Move left
        dfs(image, r, c - 1, oldColor, newColor);

        // Move right
        dfs(image, r, c + 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        // If the colors are already the same, no work is needed
        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};
