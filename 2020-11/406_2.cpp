
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 思路：排序
        int n = people.size();
        
        if (n == 0)
            return {};

        // 根据 k 进行升序排序，若 k 相同则对 h 进行升序排序
        sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
            if (a[1] != b[1])
                return a[1] < b[1];
            else
                return a[0] < b[0];
        });

        list<vector<int>> ans;

        // 将每一个人插入到正确的位置上
        for (const auto& i : people) {
            int pos = 0;
            int res = 0;
            // 找到一个位置，该位置前面的人身高的数量大于当前的 k 值，那么这个位置的前一个位置就是该人需要插入的位置（注意可能是末尾）
            // 由于我们已经对相同 k 值的人的 h 进行了生序排序，所以之前插入的人只要 k 值相同，那么就一定是严格按照 h 进行升序排序的
            // 案例：[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
            // 排序后：[[5,0], [7,0], [6,1], [7,1], [5,2], [4,4]]
            // 第一轮，插入 [5, 0]，ans = [[5,0]]，访问到 ans 末尾，直接插入末尾
            // 第二轮，插入 [7,0]，ans = [[5,0], [7,0]]，访问到 ans 末尾，直接插入末尾
            // 第三轮，插入 [6, 1]，ans = [[5,0], [7,0], [6, 1]]。访问到 ans 末尾，直接插入末尾
            // 第四轮，插入 [7, 1]，ans = [[5,0], [7,0], [6, 1], [7, 1]]，在 index = 1 时找到与 k 值相同的人数，继续往后找大于等于该 k 值的人，需要插入该人的位置，由于没找到，访问到 ans 末尾，直接插入末尾
            // 第五轮，插入 [5,2]，ans = [[5,0], [7,0], [5,2], [6, 1], [7, 1]]，在 index = 2 时找到大于 k 值的人，将当前人插入该位置
            // 第六轮，插入 [4,4]，ans = [[5,0], [7,0], [5,2], [6, 1], [4,4], [7, 1]]，在 index = 4 时找到大于 k 值的人，将当前人插入该位置
            for (auto it = ans.begin(); it != ans.end(); it++) {
                if ((*it)[0] >= i[0])
                    res++;
                if (res > i[1])
                    break;
                pos++;
            }
            auto it = ans.begin();
            advance(it, pos);
            ans.insert(it, i);
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};