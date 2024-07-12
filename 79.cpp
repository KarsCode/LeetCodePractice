class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();
        vector<vector<bool>> paths(ROWS, vector<bool>(COLS, false));

        // Define the dfs function
        function<bool(int, int, int)> dfs = [&](int r, int c, int i) {
            if (i == word.length())
                return true;
            if (r < 0 || c < 0 || r >= ROWS || c >= COLS || word[i] != board[r][c] || paths[r][c])
                return false;

            paths[r][c] = true; // Mark current position as visited

            // Check all four possible directions (up, down, left, right)
            if (dfs(r + 1, c, i + 1) || dfs(r - 1, c, i + 1) || dfs(r, c + 1, i + 1) || dfs(r, c - 1, i + 1))
                return true;

            paths[r][c] = false; // Backtrack: mark current position as not visited
            return false;
        };

        // Iterate through each cell in the board and start dfs if the first character matches
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] == word[0] && dfs(r, c, 0))
                    return true;
            }
        }

        return false;
    }
};
