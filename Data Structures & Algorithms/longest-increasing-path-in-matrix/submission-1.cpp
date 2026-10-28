class Solution {
    int dp[200][200];
    int rows, cols;
    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (dp[r][c] != 0) return dp[r][c];
        int ans = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && matrix[nr][nc] > matrix[r][c]) {
                ans = max(ans, 1 + dfs(matrix, nr, nc));
            }
        }
        return dp[r][c] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dp[i][j] = 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};