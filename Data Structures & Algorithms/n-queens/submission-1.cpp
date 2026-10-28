class Solution {
public:
    void dfs(int r, int n, string& colMask, string& diagMask, string& antiMask, vector<string>& board, vector<vector<string>>& res) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; ++c) {
            if (colMask[c] == '0' && diagMask[r - c + n - 1] == '0' && antiMask[r + c] == '0') {
                colMask[c] = '1';
                diagMask[r - c + n - 1] = '1';
                antiMask[r + c] = '1';
                board[r][c] = 'Q';
                
                dfs(r + 1, n, colMask, diagMask, antiMask, board, res);
                
                board[r][c] = '.';
                antiMask[r + c] = '0';
                diagMask[r - c + n - 1] = '0';
                colMask[c] = '0';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        string colMask(n, '0');
        string diagMask(2 * n - 1, '0');
        string antiMask(2 * n - 1, '0');
        dfs(0, n, colMask, diagMask, antiMask, board, res);
        return res;
    }
};
