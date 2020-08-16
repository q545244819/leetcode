class Solution {
public:
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(), a.end());

        int l = 0;
        int r = a.back() - a[0] + 1;

        // 二分查找
        while (r > l + 1) {
            int mid = l + (r - l) / 2;
            int t = a[0], s = 1;
            // 开始分段
            // 表示划分 s 个距离大于等于 mid 的区域
            // 若 s 越接近 m 的话，表示所求的 mid 最接近答案
            for (int i = 1; i < a.size(); i++)
                if (a[i] - t >= mid)
                    s++, t = a[i];
            if (s >= m)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};