class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        
        int n = s.length();
        int j = 0, ans = 0;

        if (n == 0) return 1;

        for (int i = 0; i < n; i++) {
            if (s[i] != s[j]) {
                counts.push_back(i - j);
                j = i;
            }
        }
        counts.push_back(n - j);

        for (int i = 0; i < counts.size() - 1; i++)
            ans += min(counts[i], counts[i + 1]);

        return ans;
    }
};