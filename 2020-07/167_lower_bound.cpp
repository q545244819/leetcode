class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, i = 0;
        // 二分查找
        // 先固定一个数
        for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++, i++) {
            int t = target - (*it);
            // 然后使用二分查找 target - numbers[i] 的数
            // 要从当前位置到数组末尾查找
            vector<int>::iterator idx = lower_bound(it + 1, numbers.end(), t);
            if (idx != numbers.end() && numbers[idx - numbers.begin()] == t) {
                l = i;
                r = idx - numbers.begin();
                break;
            }
        }
        return {l + 1, r + 1};
    }
};