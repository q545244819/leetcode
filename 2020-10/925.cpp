class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // 思路：双指针，从 s1 和 s2 的首个字符开始比较，直到 s2 的最后有一个字符
        // 1.当两个字符相同，则双指针同时向后移动
        // 2.当两个字符不相同，且第二个指针的上一个字符和当前字符相同，第二个指针向后移动一个
        // 3.当两个字符不相同，且第二个指针的上一个字符和当前字符不相同，说明不符合题意，返回 false
        // 4.当我们已经把第一个字符串完全匹配后，第二个字符还可能出现剩余字符，判断他们是否相同，不相同返回 false
        int n = name.length(), m = typed.length();
        int i = 0, j = 0;

        while (j < m) {
            if (i < n && name[i] == typed[j]) {
                i++;
                j++;
            } else if (j - 1 >= 0 && typed[j] == typed[j - 1]) {
                j++;
            } else {
                return false;
            }
        }

        return i >= n;
    }
};