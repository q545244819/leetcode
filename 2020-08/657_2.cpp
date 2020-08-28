class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'U')
                x -= 1;
            else if (c == 'R')
                y += 1;
            else if (c == 'D')
                x += 1;
            else if (c == 'L')
                y -= 1;
        }
        return x == 0 && y == 0;
    }
};