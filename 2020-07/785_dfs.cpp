class Solution {
public:
    vector<int> colors;
    bool isBipartite(vector<vector<int>>& graph) {
        colors.resize(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            if (colors[i] == 0 && !dfs(graph, i, 1)) return false;
        }
        return true;
    }

    bool dfs (vector<vector<int>>& graph, int v, int color) {
        if (colors[v] != 0) return colors[v] == color;

        colors[v] = color;

        for (int u: graph[v]) {
            if (!dfs(graph, u, -1 * color)) return false;
        }
        
        return true;
    }
};