class Solution {
public:
    string minNumber(vector<int>& nums) {
        string ans = "";
        // 比较函数使用 lambda 表达式
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
            string n = to_string(a), m = to_string(b);
            // 直接使用 int 拼接可能会溢出，所以转换成字符串
            // 转换成字符串比较
            return m + n > n + m;
        });

        for (int num: nums)
            ans += to_string(num);
            
        return ans;
    }
};