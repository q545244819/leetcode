class Solution {
public:
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        // bfs 思路
        int n = board.size(), m = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        queue<pair<int, int>> Q;
        vector<vector<bool>> book(n, vector<bool>(m, false));

        Q.push(make_pair(click[0], click[1]));
        book[click[0]][click[1]] = true;

        while (!Q.empty()) {
            pair<int, int> front = Q.front(); Q.pop();

            int res = 0;
            for (int i = 0; i < 8; i++) {
                int tx = dx[i] + front.first;
                int ty = dy[i] + front.second;

                if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] == 'M')
                    res++;
            }
            
            if (res > 0) {
                board[front.first][front.second] = '0' + res;
            } else {
                board[front.first][front.second] = 'B';
                for (int i = 0; i < 8; i++) {
                    int tx = dx[i] + front.first;
                    int ty = dy[i] + front.second;

                    if (tx >= 0 && tx < n && ty >= 0 && ty < m && !book[tx][ty] && board[tx][ty] == 'E'){
                        book[tx][ty] = true;
                        Q.push(make_pair(tx, ty));
                    }
                }
            }
        }

        return board;
    }
};