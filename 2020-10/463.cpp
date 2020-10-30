class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int ans = 0;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    int res = 4;
                    for (int d = 0; d < 4; d++) {
                        int tx = i + dx[d];
                        int ty = j + dy[d];

                        if (tx >= 0 && ty >= 0 && tx < grid.size() && ty < grid[i].size()&& grid[tx][ty] == 1)
                        res--;
                    } 
                    ans += res;
                }
            }
        }
        return ans;
    }
};