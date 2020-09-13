// 实现前缀树数据结构
class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEndOfWord;
        TrieNode () {
            isEndOfWord = false;
            children.resize(256);
        }
};
class Trie {
    public:
        TrieNode* root;
        Trie () {
            root = new TrieNode();
        }
        void insert (string word) {
            TrieNode* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (!node->children[int(word[i])])
                    node->children[int(word[i])] = new TrieNode();
                node = node->children[int(word[i])];
            }
            node->isEndOfWord = true;
        }
        bool search (string word) {
            TrieNode* node = root;
            for (int i = 0; i < word.size(); i++) {
                if (!node->children[int(word[i])])
                    return false;
                node = node->children[int(word[i])];
            }
            return node->isEndOfWord;
        }
        bool startWith (string prefix) {
            TrieNode* node = root;
            for (int i = 0; i < prefix.size(); i++) {
                if (!node->children[int(prefix[i])])
                    return false;
                node = node->children[int(prefix[i])];
            }
            return true;
        }
};
class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int n;
    int m;
    vector<vector<bool>> book;
    unordered_map<string, bool> M;
    bool ans = false;
    bool exist(vector<vector<char>>& board, string word) {
        Trie* tire = new Trie();
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            vector<bool> temp;
            temp.resize(m);
            fill(temp.begin(), temp.end(), false);
            book.push_back(temp);
        }

        tire->insert(word);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < board[i].size(); j++) {
                string s = "";
                s += board[i][j];
                // 从 board[i][j] 这个位置开始，也需要标记该位置已经被使用了
                book[i][j] = true;
                dfs(i, j, s, board, tire);
                // 结束搜索记得需要回溯
                book[i][j] = false;

                if (ans)
                    break;
            }
            if (ans)
                break;
        }

        return ans;
    }

    void dfs (int x, int y, string s, vector<vector<char>>& board, Trie*& tire) {
        if (ans) return;
        if (tire->search(s)) {
            ans = true;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || !tire->startWith(s + board[tx][ty])) continue;
            if (!book[tx][ty]) {
                book[tx][ty] = true;
                dfs(tx, ty, s + board[tx][ty], board, tire);
                book[tx][ty] = false;
            }
        }
    }
};