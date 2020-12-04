class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // 思路：哈希表 + 最小堆
        // 哈希表的 key 为 nums 数组的元素。value 为当选择 key 插入到结尾是 key - 1 的连续子序列中，组成新的连续子序列的最长子序列长度，会存在多个长度，使用最小堆，每次访问都返回最小的长度。
        int n = nums.size();

        if (n == 0) return true;
        if (n < 3) return false;

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> memo;
        
        for (const int x : nums) {
            if (memo.count(x - 1) && !memo[x - 1].empty()) {
                memo[x].push(memo[x - 1].top() + 1);
                memo[x - 1].pop(); // x - 1 的连续子序列插入 x 后形成以 x 结尾的连续子序列，将 x - 1 结尾的连续子序列长度从最小堆中删除
            } else {
                memo[x].push(1); // 无法找到以 x - 1 结尾的连续子序列，则以当前 x 作为新的连续子序列，长度为 1
            }
        }

        // 检查是否存在连续子序列的长度小于 3
        for (auto item : memo) {
            if (!item.second.empty() && item.second.top() < 3)
                return false;
        }

        return true; 
    }
};