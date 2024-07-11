class Solution {
public:
    bool checkWinner(vector<string>& board, char c) {
        // Check Horizontal
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
                return true;
        }

        // Check Vertical
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
                return true;
        }

        // Check Diagonal
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
            return true;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
            return true;

        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int countO = 0;
        int countX = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 'O')
                    countO++;
                else if (board[i][j] == 'X')
                    countX++;
            }
        }

            if (countO > countX || countX - countO >= 2)
                return false;
            return countO == countX ? !checkWinner(board, 'X')
                                    : !checkWinner(board, 'O');
        }

};