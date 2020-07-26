class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n = 0, m = 0;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        if (n == 0) return 0;
        m = matrix[0].size();
        vector<vector<int>> meno(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, dfs(i, j, matrix, meno));

        return ans;
    }

    int dfs (int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& meno) {
        if (meno[x][y] != 0) return meno[x][y];

        meno[x][y]++;

        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            
            if (tx >= 0 && ty >= 0 && tx < n && ty < m && matrix[x][y] < matrix[tx][ty]) {
                meno[x][y] = max(meno[x][y], dfs(tx, ty, matrix, meno) + 1);
            }
        }

        return meno[x][y];
    }
};