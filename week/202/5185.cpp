class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < 3; j++) {
                if (i + j < arr.size() && arr[i + j] % 2 == 1)
                    cnt++;
            }
            if (cnt >= 3)
                return true;
        }
        return false;
    }
};