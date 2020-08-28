class Solution {
public:
    bool judgeCircle(string moves) {
        // dfs 思路
        return dfs(0, 0, 0, moves);
    }

    bool dfs (int x, int y, int idx, string& moves) {
        if (idx >= moves.length() && x == 0 && y == 0) {
            return true;
        }
        if (idx >= moves.length()) return false;

        bool res = false;

        if (moves[idx] == 'U')
            res = dfs(x - 1, y, idx + 1, moves);
        else if (moves[idx] == 'R')
            res = dfs(x, y + 1, idx + 1, moves);
        else if (moves[idx] == 'D')
            res = dfs(x + 1, y, idx + 1, moves);
        else if (moves[idx] == 'L')
            res = dfs(x, y - 1, idx + 1, moves);

        return res;
    }
};