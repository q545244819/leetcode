class Solution {
public:
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1};
    int n = 0;
    int m = 0;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // 地雷被挖出
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        n = board.size();
        // 处理边界情况
        if (n == 0) return board;
        m = board[0].size();

        // 深度优先搜索
        // 从未挖出的空格八个开始扩展，且每一次统计该格子周围的炸弹数量
        // 若没有炸弹则设置为 B，否则为相邻炸弹的数量
        dfs(click[0], click[1], board);

        return board;
    }

    void dfs (int x, int y, vector<vector<char>>& board) {
        int res = nearMine(x, y, board);

        if (res > 0)
            board[x][y] = '0' + res;
        else
            board[x][y] = 'B';
        
        if (board[x][y] == 'B') {
            for (int i = 0; i < 8; i++) {
                int tx = dx[i] + x;
                int ty = dy[i] + y;
                
                if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] == 'E')
                    dfs(tx, ty, board);
            }
        }
    }

    int nearMine (int x, int y, vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i < 8; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] == 'M')
               res++;
        }

        return res;
    }
};