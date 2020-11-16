class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 思路：排序+贪心
        int n = people.size();

        if (n == 0)
            return {};
        
        // 先根据升高降序进行排序，若升高相同则对排在该前面的人的数量进行生序排序
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0])
                return a[1] <= b[1];
            else
                return a[0] > b[0];
        });

        list<vector<int>> ans;
        
        // 将每一个人插入到对应的 k 的位置上，k 位置后面的人都会往后移动一位
        // 由于我们已经将升高进行排序了，所以插入到 k 位置上的人前面的人大于等于该升高的人数一定和 k 相同
        for (int i = 0; i < n; i++) {
            auto it = ans.begin();
            advance(it, people[i][1]);
            ans.insert(it, people[i]);
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};