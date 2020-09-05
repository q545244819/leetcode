class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        
        for (int i = 1; i <= n; i++)
            arr.push_back(i);

        int i = 0;
        string ans = "";

        do {
            if (i >= k - 1)
                break;
            i++;
        } while (next_permutation(arr.begin(), arr.end()));

        for (int n :arr)
            ans += to_string(n);

        return ans;
    }
};