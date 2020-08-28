class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // 继承 57-1 题目的思路：双指针
        // 指针 1 指向数值 1，指针 2 指向数值 2
        // 1. 若指针 1 到指针 2 范围到内的数字相加等于 target，记录答案且指针 2 向后移动一位
        // 2. 若指针 1 到指针 2 范围到内的数字相加小于 target，指针 2 向后移动一位
        // 3. 若指针 1 到指针 2 范围到内的数字相加大于 target，指针 1 向后移动一位
        // 4. 两个指针相遇，退出循环
        vector<vector<int>> ans;
        int l = 1, r = 2, sum = l + r;
        while (l < r) { // 4
            if (sum == target) { // 1
                vector<int> temp;
                for (int i = l; i <= r; i++)
                    temp.push_back(i);
                ans.push_back(temp);
                r++;
                sum += r;
            } else if (sum < target) { // 2
                r++;
                sum += r;
            } else if (sum > target) { // 3
                sum -= l;
                l++;
            }
        }
        return ans;
    }
};