const double N = 24;

class Solution {
public:
    bool ans = false;
    bool judgePoint24(vector<int>& nums) {
        vector<double> arr;
        for (int num : nums)
            arr.push_back(1.0 * num);
        
        permutation(arr, 0);

        return ans;
    }
    void permutation (vector<double>& arr, int step) {
        if (ans) return;
        if (step >= 4) {
            ans = dfs(arr[0], arr[1], arr[2], arr[3]);
            return;
        }
        for (int i = step; i < 4; i++) {
            swap(arr[step], arr[i]);
            permutation(arr, step + 1);
            swap(arr[step], arr[i]);
        }
    }
    bool dfs (double a, double b, double c, double d) {
        return dfs(a + b, c, d) ||
            dfs(a - b, c, d) ||
            dfs(a * b, c, d) ||
            dfs(a / b, c, d);
    }
    bool dfs (double a, double b, double c) {
        return dfs(a + b, c) ||
            dfs(a - b, c) ||
            dfs(a * b, c) ||
            dfs(a / b, c) ||
            dfs(b - a, c) ||
            dfs(b / a, c) ||
            dfs(a, b + c) ||
            dfs(a, b - c) ||
            dfs(a, b * c) ||
            dfs(a, b / c);
    }
    bool dfs (double a, double b) {
        return abs(a + b - N) <= 1e-6 ||
            abs(a - b - N) <= 1e-6 ||
            abs(a * b - N) <= 1e-6 ||
            abs(a / b - N) <= 1e-6 ||
            abs(b - a - N) <= 1e-6 ||
            abs(b / a - N) <= 1e-6;
    }
};