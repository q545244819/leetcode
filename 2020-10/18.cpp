class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // 思路：同三数之和一样，只是又多了一层循环
        // 先固定 n - 2 个数，然后再使用双指针求出剩下的两个数 a 和 b
        // 注意使用双指针求出第一个结果后，不着急退出，可能存在 a' 和 b' 也能符合条件，所以需要继续移动指针

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) // 若当前的 num[i] 与 num[i - 1] 相同，则跳过
                continue; // 因为 num[i] 可能的结果已经求出来了
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) // 若当前的 num[j] 与 num[j - 1] 相同，则跳过
                    continue; // 因为 num[i] + nums[j] 可能的结果已经求出来了
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) { // 当遇到两个符合条件的数，即 num[i] + num[j] + a + b = target
                        ans.push_back({ nums[i], nums[l], nums[r], nums[j] }); // 添加到答案中
                        // 这里两个循环跳过所有相同的数，避免出现重复的答案
                        while (l < r && nums[l] == nums[l + 1])
                            l++;
                        while (l < r && nums[r] == nums[r - 1])
                            r--;
                        // 继续移动指针，因为可能存在 a' 和 b' 也能够构成 target
                        l++;
                        r--;
                    }
                    else if (sum > target)
                        r--;
                    else if (sum < target)
                        l++;
                }
            }
        }

        return ans;
    }
};