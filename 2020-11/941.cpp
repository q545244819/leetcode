class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        // 思路：双指针，找到山顶的位置，且需要判断山顶位置是否在最左边或者最右边
        int n = A.size();
        int l = 0, r = n - 1;

        if (n < 3)
            return false;

        for (; l < n - 1; l++)
            if (A[l] >= A[l + 1])
                break;
        for (; r > 0; r--)
            if (A[r] >= A[r - 1])
                break;

        return (l == r && l > 0 && l < n - 1);
    }
};