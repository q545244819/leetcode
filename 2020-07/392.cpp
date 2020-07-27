class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 双指针
        int p1 = 0, p2 = 0;
        
        while (p1 < s.length() && p2 < t.length()) {
            if (s[p1] != t[p2]) {
                p2++;
            } else {
                p1++;
                p2++;
            }
        }

        return p1 == s.length();
    }
};