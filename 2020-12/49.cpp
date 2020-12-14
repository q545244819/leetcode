class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 思路：哈希表+排序
        unordered_map<string, int> book;
        int len = 0;
        vector<vector<string>> ans;
        string temp;

        for (const string& str : strs) {
            temp = str;
            sort(temp.begin(), temp.end());
            if (book.find(temp) == book.end()) {
                book[temp] = len++;
                ans.push_back({ str });
            } else {
                ans[book[temp]].push_back(str);
            }
        }

        return ans;
    }
};