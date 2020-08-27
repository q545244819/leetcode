class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> G;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 需要前置知识：欧拉回路
        for (vector<string> e : tickets)
            G[e[0]].push(e[1]);
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string u) {
        while (G.count(u) && !G[u].empty()) {
            string v = G[u].top(); G[u].pop();
            
            dfs(v);
        }
        ans.push_back(u);
    }
};