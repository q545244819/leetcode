class Solution {
public:
    vector<int> color;
    vector<vector<int>> G;
    vector<int> indeg;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 0) return true;
        
        color = vector<int>(numCourses);
        G = vector<vector<int>>(numCourses, vector<int>(numCourses, 0));
        indeg = vector<int>(numCourses);
        
        for (vector<int> arr : prerequisites) {
            G[arr[0]][arr[1]] = 1;
            indeg[arr[0]]++;
        }

        for (int u = 0; u < numCourses; u++)
            if (color[u] == 0)
                bfs(u, numCourses);
        
        for (int i : indeg)
            if (i > 0)
                return false;

        return true;
    }

    void bfs (int u, int numCourses) {
        queue<int> Q;

        Q.push(u);

        color[u] = 1;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            cout << u << endl;
            for (int v = 0; v < numCourses; v++) {
                if (G[u][v]) {
                    if (indeg[v] - 1 == 0 && color[v] == 0) {
                        indeg[v]--;
                        color[v] = 1;
                        Q.push(v);
                    }
                }
            }
        }
    }
};