class Solution {
public:
    int dx[4] = {1, -1, 0, 0} ;
    int dy[4] = {0, 0, 1, -1};
    vector<vector<bool>> book;
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0)
            return false;
        int m = board[0].size();
        book = vector<vector<bool>>(n, vector<bool>(m, false));
        bool ans = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                book[i][j] = true;
                if (word[0] == board[i][j] && dfs(i, j, 1, board, word)) {
                    ans = true;
                    break;
                }
                book[i][j] = false;
            }
            if (ans)
                break;
        }
        return ans;
    }

    bool dfs (int x, int y, int idx, vector<vector<char>>& board, string word) {
        bool res = false;
        // cout << book[x][y] << " " << idx << endl;
        if (idx >= word.length()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            // cout << "tx = " << tx << " ty = " << ty << endl;
            if (tx >= 0 && ty >= 0 && tx < board.size() && ty < board[0].size() && !book[tx][ty] && board[tx][ty] == word[idx]) {
                book[tx][ty] = true;
                res = dfs(tx, ty, idx + 1, board, word);
                book[tx][ty] = false;
            }
            if (res)
                break;
        }

        return res;
    }
};