class Solution {
public:
    string reorganizeString(string S) {
        // 思路：最大堆，每轮取出字符次数最多的字符，若当前字符串不是空串，且最后一个字符与当前最大出现次数字符相同，则取出次大出现次数字符，若不存在次大出现次数字符，直接返回空字符串。将当前最大/次大出现次数字符拼接到结果字符串后，若栈中有本轮未使用到的字符，则将这些字符放回最大堆中。且本轮使用到的字符，次数减1，若次数不为零，同样将该字符放回最大堆中。重复以上步骤，直到最大堆为空。
        int n = S.length();

        if (n == 0)
            return "";
        
        vector<int> memo(27, 0);
        priority_queue<pair<int, char>> PQ;

        for (const char& c : S)
            memo[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (memo[i]) {
                PQ.push({ memo[i], i + 'a' });
            }
        }
        
        
        int len = 0;
        string ans = "";

        while (!PQ.empty()) {
            stack<pair<int, char>> sstack;
            len = ans.size();
            pair<int, char> top = PQ.top(); PQ.pop();

            while (len && ans[len - 1] == top.second && PQ.size()) {
                sstack.push(top);
                top = PQ.top(); PQ.pop();
            }

            if (ans[len - 1] == top.second)
                return "";

            ans += top.second;

            if (top.first - 1 > 0)
                PQ.push({ top.first - 1, top.second });
            
            while (!sstack.empty())
                PQ.push(sstack.top()), sstack.pop();
        }

        return ans;
    }
};