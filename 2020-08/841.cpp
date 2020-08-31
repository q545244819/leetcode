class Solution {
public:
    vector<bool> visited;
    bool ans = false;
    int cnt = 0;
    int n = 0;
    bool canVisitAllRooms(vector<vector<int>>& g) {
        n = g.size();
        visited = vector<bool>(n, false);
        visited[0] = true;
        cnt++;
        dfs(0, g);
        return ans;
    }

    void dfs (int u, vector<vector<int>>& g) {
        if (ans)
            return;
        bool res = false;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!visited[v]) {
                // 不需要回溯
                res = true;
                visited[v] = true;
                cnt++;
                dfs(v, g);
                
            }
        }
        // 当前顶点 u 已经无法继续走了，判断是否访问过所有顶点
        if (!res) {
            ans = cnt == n;
        }
    }
};
