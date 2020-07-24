class Solution {
public:
    vector<int> meno;
    bool divisorGame(int N) {
        meno.resize(N + 1);
        fill(meno.begin(), meno.end(), -1);
        return dfs(N);
    }

    bool dfs (int N) {
        // cout << N << endl;
        if (N == 0 || N == 1) return false;
        if (meno[N] != -1) return meno[N];

        bool res = false;

        for (int i = 1; i < N; i++) {
            if (N % i == 0) {
                res = res || !dfs(N - i);
            }
        }

        return meno[N] = res ? 1 : 0;
    }
};