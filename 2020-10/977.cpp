class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // 思路：使用双指针，两边绝对值进行比较把较大的值的平方推入结果数组，最后需要将结果数组反转
        vector<int> ans;
        int n = A.size();

        int l = 0, r = n - 1;

        while (l <= r) {
            if (abs(A[l]) > abs(A[r]))
                ans.push_back(A[l] * A[l++]);
            else
                ans.push_back(A[r] * A[r--]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};