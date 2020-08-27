class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for (int num : nums)
            res ^= num;
        //cout << res << endl;
        int cnt = 1;
        while ((res & 1) == 0) {
            res >>= 1;
            cnt <<= 1;
        }
        //cout << cnt << endl;
        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & cnt) > 0) {
                //cout << "a ^= " << num << endl;
                a ^= num;
            } else {
                //cout << "b ^= " << num << endl;
                b ^= num;
            }
        }
        return {a, b};
    }
};