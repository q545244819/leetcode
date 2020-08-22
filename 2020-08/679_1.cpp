const double N = 24;
const int M = 4;

class Solution {
public:
    bool ans = false;
    vector<vector<vector<double>>> memo;
    bool judgePoint24(vector<int>& nums) {
        permutation(nums, 0);
        return ans;
    }
    void permutation (vector<int>& arr, int step) {
        if (ans) return;
        if (step >= 4) {
            memo = vector<vector<vector<double>>>(M, vector<vector<double>>(M));
            vector<double> res = dfs(0, arr.size() - 1, arr);
            for (double num : res) {
                if (abs(N - num) <= 1e-6) {
                    ans = true;
                    break;
                }
            }
            return;
        }
        for (int i = step; i < 4; i++) {
            swap(arr[step], arr[i]);
            permutation(arr, step + 1);
            swap(arr[step], arr[i]);
        }
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
