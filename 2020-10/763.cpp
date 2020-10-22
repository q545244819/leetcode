
class Solution {
public:
    vector<int> partitionLabels(string S) {
        // 思路：记录每一个字符出现的最后位置
        // 通过双指针找到最长的片段，尾指针根据当前字符的最后出现位置和当前尾指针位置求最大值
        // 若当前 i 等于尾指针位置，表示已经找到了一个最长的判断，将头指针设置为尾指针 + 1
        // 重复以上的过程
        vector<int> mmax(27, 0);
        vector<int> ans;
        int n = S.length();

        for (int i = 0; i < n; i++)
            mmax[S[i] - 'a'] = i;
        
        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            end = max(end, mmax[S[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};