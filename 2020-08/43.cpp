class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        int len = n1 + n2;
        int res[len];
        string ans = "";
        
        memset(res, 0, sizeof(res));

        for (int j = n2 - 1; j >= 0; j--) {
            // cout << num2[j] << endl;
            for (int i = n1 - 1; i >= 0; i--) {
                int index = i + j + 1;
                res[index] += (num1[i] - '0') * (num2[j] - '0');
                // cout << index << " " << res[index] << endl;
                if (res[index] >= 10) {
                    res[index - 1] += res[index] / 10;
                    res[index] %= 10;
                }
            }
        }
        
        bool zero = true;
        for (int i = 0; i < len; i++) {
            if (res[i] || !zero) {
                ans += res[i] + '0';
                zero = false;
            }
        }
        if (zero)
            ans = "0";

        return ans;
    }
};