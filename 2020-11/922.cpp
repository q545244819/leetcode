class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int odd = 1, even = 0;
        vector<int> ans(n);
        
        for (const int& i : A) {
            if (i & 1) {
                ans[odd] = i;
                odd += 2;
            } else {
                ans[even] = i;
                even += 2;
            }
        }

        return ans;
    }
};