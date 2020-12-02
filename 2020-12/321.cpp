class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // 思路：把问题分解为三个小问题
        // 1.求数组取 k 个值组成的最大值数组
        // 2.求两个最大值数组合并后的数组
        // 3.求出结果最大值数组

        int n1 = nums1.size(), n2 = nums2.size();
        
        // 边界处理
        if ((n1 == 0 && n2 == 0) || k > n1 + n2) return {};
        if (n1 == 0)
            return nums2;
        if (n2 == 0)
            return nums1;

        vector<int> ans;

        for (int i = 0; i <= k; i++) {
            // 减枝
            if (i > n1 || k - i > n2) continue;
            
            // 分别求数组 1 的取 i 个组成的最大值和数组 2 取 k - i 个组成的最大值
            // 最后合并这两个最大值数组，生成新的长度为 k 的最大值数组，并且和已保存的最大值数组结果比较
            auto left = maxNumber(nums1, i);
            auto right = maxNumber(nums2, k - i);
            auto merged = merge(left, right);
            
            ans = max(ans, merged);
        }

        return ans;
    }
    // 从数组中取 k 个数组成的最大值，思路：递减单调栈。
    vector<int> maxNumber(vector<int>& arr, int k) {
        if (k == 0) return {};

        int n = arr.size();
        int to_pop = n - k;
        vector<int> sstack;
        
        sstack.push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            while (to_pop > 0 && !sstack.empty() && sstack.back() < arr[i]) {
                sstack.pop_back();
                to_pop--;
            }
            sstack.push_back(arr[i]);
        }

        sstack.resize(k);
        
        return sstack;
    }
    // 合并两个数组，两个指针的位置比较，将大的数值放到结果中，若出现相同，则一直比较直到遇到不同，然后在判断大小，最后将大的数组的值放到结果数组中，若两个相同，则取第一个数组的值放到数组中。
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> res;

        while (p1 < n1 && p2 < n2) {
            if (nums1[p1] == nums2[p2]) {
                int i = p1, j = p2;
                while (i < n1 && j < n2 && nums1[i] == nums2[j]) {
                    i++;
                    j++;
                }
                if (i >= n1 && j >= n2) {
                    res.push_back(nums1[p1++]);
                } else if (i >= n1) {
                    res.push_back(nums2[p2++]);
                } else if (j >= n2) {
                    res.push_back(nums1[p1++]);
                } else {
                    res.push_back(nums1[i] > nums2[j] ? nums1[p1++] : nums2[p2++]);
                }
            } else if (nums1[p1] > nums2[p2]) {
                res.push_back(nums1[p1++]);
            } else if (nums1[p1] < nums2[p2]) {
                res.push_back(nums2[p2++]);
            }
        }
        while (p1 < n1) res.push_back(nums1[p1++]);
        while (p2 < n2) res.push_back(nums2[p2++]);

        return res;
    }
};