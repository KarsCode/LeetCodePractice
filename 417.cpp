#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // DFS function
        function<void(int, int, vector<vector<bool>>&, int)> dfs = [&](int r, int c, vector<vector<bool>>& visit, int prevHeight) {
            if (r < 0 || c < 0 || r >= ROWS || c >= COLS || heights[r][c] < prevHeight || visit[r][c]) return;
            visit[r][c] = true;
            dfs(r + 1, c, visit, heights[r][c]);
            dfs(r - 1, c, visit, heights[r][c]);
            dfs(r, c + 1, visit, heights[r][c]);
            dfs(r, c - 1, visit, heights[r][c]);
        };

        // Initialize DFS from the borders for both Pacific and Atlantic
        for (int i = 0; i < ROWS; ++i) {
            dfs(i, 0, pac, heights[i][0]);        // Pacific
            dfs(i, COLS - 1, atl, heights[i][COLS - 1]); // Atlantic
        }

        for (int i = 0; i < COLS; ++i) {
            dfs(0, i, pac, heights[0][i]);        // Pacific
            dfs(ROWS - 1, i, atl, heights[ROWS - 1][i]); // Atlantic
        }

        // Find common cells in both sets
        vector<vector<int>> result;
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (pac[i][j] && atl[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
