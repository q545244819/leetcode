    const int N = 10;

    class Solution {
    public:
        vector<vector<bool>> rows;
        vector<vector<bool>> cols;
        vector<vector<bool>> book;
        bool ans = false;
        void solveSudoku(vector<vector<char>>& board) {
            // 思路：回溯算法
            rows = vector<vector<bool>>(N, vector<bool>(N, false));
            cols = vector<vector<bool>>(N, vector<bool>(N, false));
            book = vector<vector<bool>>(N, vector<bool>(N, false));
            
            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (board[i][j] != '.') {
                        int n = board[i][j] - '0';
                        rows[i][n] = true;
                        cols[j][n] = true;
                        book[getZone(i, j)][n] = true;
                    }
                }
            }

            dfs(0, 0, board);
        }
        // 重要：使用 O(1) 的时间复杂度求坐标(x,y)在九宫格的某一格 
        int getZone (int x, int y) {
            return x / 3 * 3 + y / 3;
        }
        void dfs (int x, int y, vector<vector<char>>& board) {
            if (x >= N - 1) {
                ans = true;
                return;
            }
            if (board[x][y] != '.') {
                y++;
                if (y >= N - 1) {
                    y = 0;
                    x++;
                }
                dfs(x, y, board);
            } else {
                for (int i = 1; i <= N - 1; i++) {
                    int zone = getZone(x, y);
                    if (rows[x][i] || cols[y][i] || book[zone][i])
                        continue;
                    rows[x][i] = cols[y][i] = book[zone][i] = true;
                    board[x][y] = i + '0';
                    dfs(x, y, board);
                    if (ans)
                        break;
                    rows[x][i] = cols[y][i] = book[zone][i] = false;
                    board[x][y] = '.';
                }
            }
        }
    };