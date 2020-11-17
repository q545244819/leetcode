class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // 思路：bfs
        if (R == 0 || C == 0)
            return {};

        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        vector<vector<int>> ans;

        visited[r0][c0] = true;
        Q.push({ r0, c0 });

        while (!Q.empty()) {
            pair<int, int> front = Q.front(); Q.pop();
            
            ans.push_back({ front.first, front.second });

            for (int i = 0; i < 4; i++) {
                int tx = dx[i] + front.first;
                int ty = dy[i] + front.second;

                if (tx >= 0 && ty >= 0 && tx < R && ty < C && !visited[tx][ty]) {
                    visited[tx][ty] = true;
                    Q.push({ tx, ty });
                }
            }
        }

        return ans;
    }
};