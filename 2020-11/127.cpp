class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 思路：单向 bfs
        if (wordList.size() == 0) {
            return 0;
        }

        queue<pair<string, int>> Q;
        unordered_map<string, bool> memo;

        for (const string& word : wordList)
            memo[word] = true;

        Q.push({ beginWord, 1 });

        memo[beginWord] = true;

        while (!Q.empty()) {
            pair<string, int> front = Q.front(); Q.pop();
            string cur = front.first;
            
            if (cur == endWord) {
                return front.second;
            }

            for (int i = 0; i < cur.length(); i++) {
                char ch = cur[i];
                for (char c = 'a'; c <= 'z'; c++) { // 开始枚举字符串每一个可能出现的字符
                    if (c == cur[i]) // 剪枝 1，和当前位置相同字符跳过
                        continue;
                    cur[i] = c;
                    if (memo[cur]) { // 剪枝 2，只能变换到存在 wordList 中的字符串
                        if (cur == endWord) {
                            return front.second + 1;
                        }
                        memo.erase(cur); // 剪枝 3，当变换到 wordList 的某个字符后，由于题目特性，是不可能在变换回来这个字符串的，所以把该字符串从哈希表中删除
                        Q.push({ cur, front.second + 1 });
                    }
                }
                cur[i] = ch;
            }
        }

        return 0;
    }
};