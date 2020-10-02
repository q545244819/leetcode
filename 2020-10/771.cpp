class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        vector<int> memo(255, 0);
        
        for (int i = 0; i < J.size(); i++)
            memo[J[i] - 'A']++;

        for (int i = 0; i < S.size(); i++)
            if (memo[S[i] - 'A'])
                ans++;
        
        return ans;
    }
};