class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        
        if (n == 0) return;
        
        int m = board[0].size();

        // 与不符合条件 O 相连接的 O 处理
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, 'x', 'O', board);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, 'x', 'O', board);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(0, i, 'x', 'O', board);
            if (board[n - 1][i] == 'O')
                dfs(n - 1, i, 'x', 'O', board);
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++)
                if (board[i][j] == 'O')
                    dfs(i, j, 'X', 'O', board);
        }

        // 与不符合条件 O 相连接的 O 处理
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'x')
                dfs(i, 0, 'O', 'x', board);
            if (board[i][m - 1] == 'x')
                dfs(i, m - 1, 'O', 'x', board);
        }
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'x')
                dfs(0, i, 'O', 'x', board);
            if (board[n - 1][i] == 'x')
                dfs(n - 1, i, 'O', 'x', board);
        }
    }

    void dfs (int x, int y, char c, char t,vector<vector<char>>& board) {
        board[x][y] = c;

        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;

            if (tx >= 0 && ty >= 0 && tx < board.size() && ty < board[0].size() && board[tx][ty] == t) {
                dfs(tx, ty, c, t, board);
            }
        }
    }
};