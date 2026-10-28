class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        
        rows, cols = len(matrix), len(matrix[0])
        dp = {}
        
        def dfs(r, c):
            if (r, c) in dp:
                return dp[(r, c)]
            
            res = 1
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and matrix[nr][nc] > matrix[r][c]:
                    res = max(res, 1 + dfs(nr, nc))
            
            dp[(r, c)] = res
            return res

        ans = 0
        for r in range(rows):
            for c in range(cols):
                ans = max(ans, dfs(r, c))
        return ans