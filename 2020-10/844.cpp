class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // 思路：双指针，从后往前对比，遇到 # 字符记录需要跳过前面字符的次数，若有跳过次数不为 0，则跳过当前字符，继续往前移动。
        // 时间复杂度O(n + m)，空间复杂度O(1)
        int p1 = S.size() - 1, p2 = T.size() - 1;
        int skipS = 0, skipT = 0;

        while (p1 >= 0 || p2 >= 0) {
            while (p1 >= 0) {
                if (S[p1] == '#') {
                    skipS++;
                    p1--;
                } else if (skipS > 0) {
                    skipS--;
                    p1--;
                } else { // 遇到不是退格符的字符且该字符串不需要被删除
                    break;
                }
            }
            while (p2 >= 0) {
                if (T[p2] == '#') {
                    skipT++;
                    p2--;
                } else if (skipT > 0) {
                    skipT--;
                    p2--;
                } else { // 遇到不是退格符的字符且该字符串不需要被删除
                    break;
                }
            }
            
            if (p1 < 0 && p2 < 0) // 两个字符串都被退格符删除完的情况
                return true;
            else if (p1 < 0 || p2 < 0) // 某一个字符串被退格符删除完的情况
                return false;
            
            if (S[p1] != T[p2])
                return false;
            
            p1--;
            p2--;
        }

        return true;
    }
};