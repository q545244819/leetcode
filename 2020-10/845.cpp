class Solution {
public:
    int longestMountain(vector<int>& A) {
        // 思路：双指针中心扩散，需要注意一些特殊的案例如：[2,3]或者[3,2]这种案例的情况都是低高或者高低，题目要求的是低高低
        int ans = 0;
        int n = A.size();

        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            bool leftFlag = false;
            bool rightFlag = false;

            while (l > 0 && A[l] > A[l - 1]) {
                l--;
                leftFlag = true;
            }
            while (r < n - 1 && A[r] > A[r + 1]) {
                r++;
                rightFlag = true;
            }
            
            if (leftFlag && rightFlag)
                ans = max(r - l + 1, ans);
        }

        return ans;
    }
};