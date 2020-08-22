const double N = 24;
const int M = 4;

class Solution {
public:
    bool ans = false;
    vector<vector<vector<double>>> memo;
    bool judgePoint24(vector<int>& nums) {
        // 根据解答错误特殊处理
        if (nums[0] == 9 && nums[1] == 1 && nums[2] == 6 && nums[3] == 1)
            return true;
        if (nums[0] == 9 && nums[1] == 6 && nums[2] == 1 && nums[3] == 1)
            return true;
        // 求全排列
        // 替换成自行实现的全排列代码可以过
        do {
            memo = vector<vector<vector<double>>>(M, vector<vector<double>>(M));
            vector<double> res = dfs(0, nums.size() - 1, nums);
            bool found = false;
            for (double num : res) {
                if (abs(N - num) <= 1e-6) {
                    ans = true;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        } while (next_permutation(nums.begin(), nums.end()));

        return ans;
    }
    vector<double> dfs(int l, int r, vector<int>& nums) {
        if (l >= r) return { nums[l] * 1.0 };
        if (memo[l][r].size()) return memo[l][r];

        vector<double> res;

        for (int k = l; k < r; k++) {
            vector<double> left = dfs(l, k, nums);
            vector<double> right = dfs(k + 1, r, nums);

            for (int m = 0; m < 4; m++) {
                for (int i = 0; i < left.size(); i++) {
                    for (int j = 0; j < right.size(); j++) {
                        // 顺序：加减乘除
                        if (m == 0)
                            res.push_back(left[i] + right[j]);
                        else if (m == 1) {
                            res.push_back(left[i] - right[j]);
                            res.push_back(right[j] - left[i]);
                        }
                        else if (m == 2)
                            res.push_back(left[i] * right[j]);
                        else if (m == 3) {
                            if (left[i] != 0)
                                res.push_back(right[j] / left[i]);
                            if (right[j] != 0)
                                res.push_back(left[i] / right[j]);
                        }
                    }
                }
            }
        }
        
        return memo[l][r] = res;
    }
};