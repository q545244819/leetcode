class Solution {
public:
    string predictPartyVictory(string senate) {
        // 思路：贪心算法
        // 若当前议员可以投票，则禁止下一个不同阵营的议员不允许投票。直到最后只剩下同一组议员。该组议员获胜。
        // base case：若输入中只存在同一组议员，则该组议员获胜。
        int n = senate.length();

        if (n == 0)
            return "";

        queue<int> Q;
        int radiants = 0, dires = 0;
        int shouldBanRadiant = 0;
        int shouldBanDire = 0;

        for (int i = 0; i < n; i++) {
            char ch = senate[i];
            if (ch == 'R')
                radiants++;
            else if (ch == 'D')
                dires++;
            Q.push(i);
        }

        if (radiants == 0)
            return "Dire";
        if (dires == 0)
            return "Radiant";

        while (Q.size() > 1) {
            int idx = Q.front(); Q.pop();
            
            if (radiants == 0)
                return "Dire";
            if (dires == 0)
                return "Radiant";

            if (shouldBanRadiant > 0 && senate[idx] == 'R') {
                shouldBanRadiant--;
                radiants--;
                continue;
            }
            if (shouldBanDire > 0 && senate[idx] == 'D') {
                shouldBanDire--;
                dires--;
                continue;
            }

            if (senate[idx] == 'R')
                shouldBanDire++;
            else if (senate[idx] == 'D')
                shouldBanRadiant++;

            Q.push(idx);
        }

        return senate[Q.front()] == 'R' ? "Radiant" : "Dire";
    }
};