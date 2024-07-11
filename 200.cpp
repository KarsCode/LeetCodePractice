class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

         function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') return;
            grid[x][y] = '0'; // Mark current cell as visited
            
            // Recursively visit all 4 neighbors
            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                dfs(nx, ny);
            }
        };

        // Traverse the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    result++;
                    dfs(i, j); // Visit all connected land cells
                }
            }
        }

        return result;
    }
};