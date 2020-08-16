class Solution {
public:
    int minOperations(int n) {
        int i = 0, j = n - 1, ans = 0;
        
        vector<int> arr;
        
        for (int k = 0; k < n; k++)
            arr.push_back((2 * k) + 1);
        
        while (i < j) {
            int t = (arr[i] + arr[j]) / 2;
            ans += t - arr[i];
            i++;
            j--;
        }
        
        return ans;
    }
};