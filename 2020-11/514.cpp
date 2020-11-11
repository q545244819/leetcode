class State {
    public:
        int step;
        int cur;
        int res;
        State (int step, int cur, int res) {
            this->step = step;
            this->cur = cur;
            this->res = res;
        }
        bool operator < (const State &s) const {
            return step > s.step;
        }
};

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // 思路：优先队列实现 bfs
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> pos(27, vector<int>());
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, INT_MAX));

        for (int i = 0; i < n; i++) {
            pos[ring[i] - 'a'].push_back(i);
        }

        if (n == 0 || m == 0)
            return 0;
        
        priority_queue<State> PQ;

        for (const int& idx : pos[key[0] - 'a']) {
            PQ.push(State(min(idx, n - idx) + 1, idx, 1));
        }

        while (!PQ.empty()) {
            State top = PQ.top(); PQ.pop();

            if (top.res >= m) {
                return top.step;
            }

            for (const int& idx : pos[key[top.res] - 'a']) {
                int dist = abs(top.cur - idx);
                int step = top.step + min(dist, n - dist) + 1;
                if (step < memo[idx][top.res + 1]) {
                    memo[idx][top.res + 1] = step;
                    PQ.push(State(step, idx, top.res + 1));
                }
            }
        }

        return 0;
    }
};