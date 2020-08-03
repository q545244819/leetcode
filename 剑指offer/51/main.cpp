const int LEN = 50000 / 2 + 2;

class Solution {
public:
    int L[LEN];
    int R[LEN];
    int ans = 0;
    int reversePairs(vector<int>& nums) {
        // 思路：归并排序
        // 在归并的过程中统计逆序对的数量
        mergeSort(nums, 0, nums.size());
        return ans;
    }

    // right 的默认取值范围是数组的实际长度
    void mergeSort (vector<int>& nums, int left, int right) {
        if (left + 1 < right) {
            int mid = left + ((right - left) >> 1);
            mergeSort(nums, left, mid);
            mergeSort(nums, mid, right);
            merge(nums, left, mid, right);
        }
    }

    void merge (vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left;
        int n2 = right - mid;
        for (int i = 0; i < n1; i++) L[i] = nums[left + i];
        for (int i = 0; i < n2; i++) R[i] = nums[mid + i];

        int i = n1 - 1, j = n2 - 1, k = right - 1;
        
        while (i >= 0 && j >= 0) {
            if (L[i] > R[j]) {
                // 若左边的数组的最大的数大于右边数组中最大的数，则表示左边数组中最大的数和右边数组所有元素构成逆序对
                // 例如，左边：[5,7] 和右边 [4,6]
                // 左边数组最大的数字 7
                // 右边数组最大的数字 6
                // 7 > 6
                // 则表示右边数组的所有元素都与 7 构成逆序对
                ans += j + 1;
                nums[k--] = L[i--];
            } else {
                nums[k--] = R[j--];
            }
        }
        while (i >= 0) {
            nums[k--] = L[i--];
        }
        while (j >= 0) {
            nums[k--] = R[j--];
        }
    }
};