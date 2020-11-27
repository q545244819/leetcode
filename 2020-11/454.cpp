class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // 思路：哈希表
        // 1.先求解 A 和 B 两个数组中元素相加的结果情况，并且将每一个结果出现的次数记录在哈希表中
        // 2.再求解 C 和 D 两个数组中元素相加的结果的负数是否出现在哈希表中，若出现则表示有 n 个元素可以组成 0，答案加上 n
        unordered_map<int, int> memo;
        int ans = 0;

        for (const int& a : A)
            for (const int& b : B)
                memo[a + b]++;
        
        for (const int& c : C)
            for (const int& d : D)
                ans += memo[-(c + d)];

        return ans;
    }
};