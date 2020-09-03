class Solution {
public:
    // 思路：回溯算法
    // 使用 O(1) 的时间判断皇后是否会被攻击
    vector<bool> row; // 行
    vector<bool> col; // 列
    vector<bool> dpos; // 左下方
    vector<bool> dneg; // 右下方
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {        
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int j = 0; j < n; j++)
                s += '.';
            res.push_back(s);
        }

        row = vector<bool>(n, false);
        col = vector<bool>(n, false);
        dpos = vector<bool>(2 * n - 1, false);
        dneg = vector<bool>(2 * n - 1, false);
        
        dfs(0, res, n);

        return ans;
    }

    void dfs (int i, vector<string>& res, int n) {
        // 递归出口，找到了一种摆放皇后的方案
        if (i >= n) {
            ans.push_back(res);
            return;
        }

        for (int j = 0; j < n; j++) {
            // 跳过会被攻击的位置
            if (row[i] || col[j] || dpos[i + j] || dneg[i - j + (n - 1)])
                continue;
            
            row[i] = true;
            col[j] = true;
            dpos[i + j] = true;
            dneg[i - j + (n - 1)] = true;
            res[i][j] = 'Q';
            dfs(i + 1, res, n);
            res[i][j] = '.';
            dneg[i - j + (n - 1)] = false;
            dpos[i + j] = false;
            col[j] = false;
            row[i] = false;
        }
    }
};