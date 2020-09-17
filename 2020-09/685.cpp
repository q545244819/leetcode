class DisjointSet {
  public:
    vector<int> rank, p;

    DisjointSet () {}
    DisjointSet (int size) {
      p.resize(size);
      rank.resize(size);

      for (int i = 0; i < size; i++)
        makeSet(i);
    }

    // 创建仅包含元素 x 的新集合
    void makeSet (int x) {
      p[x] = x;
      rank[x] = 0;
    }

    bool same (int x, int y) {
      return findSet(x) == findSet(y);
    }

    // 合并指定的元素 x，y
    void unite (int x, int y) {
      link(findSet(x), findSet(y));
    }

    void link (int x, int y) {
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }

    // 求包含元素 x 的集合的“代表”元素
    int findSet (int x) {
      stack<int> S;
      int root;

      S.push(x);

      while (S.top() != p[S.top()]) {
        S.push(p[S.top()]);
      }
      
      // 传入结点 x 所在树的“代表”结点
      root = S.top(); S.pop();

      // 压缩路径
      while (S.size()) {
        p[S.top()] = root;
        S.pop();
      }

      return root;
    }

    int findSet_recursion (int x) {
      if (x != p[x])
        p[x] = findSet_recursion(p[x]); // 路径压缩
      return p[x];
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 思路：根据题意有 N 个节点且有 N 条边，有一条边是多余的，意思就是有一个结点的入度为 2，需要单独处理。
        int n = edges.size();
        DisjointSet ds = DisjointSet(n + 1);
        vector<int> indeg(n + 1, 0);
        int node = -1; // 入度为 2 的节点
        for (vector<int> e : edges) { // 计算每一个节点的入度
            indeg[e[1]]++;
            if (indeg[e[1]] > 1)
                node = e[1];
        }
        vector<vector<int>> E; // 存放入度为 2 的节点的所有边
        vector<int> res;
        for (vector<int> e : edges) {
            if (node == e[1]) {
                E.push_back(e);
                continue;
            }
            if (ds.findSet(e[0]) != ds.findSet(e[1])) // 连接两个节点
                ds.unite(e[0], e[1]);
            else // 存在回路，可以删除当前边 e
                res = e;
        }
        for (vector<int> e : E) {
            if (ds.findSet(e[0]) != ds.findSet(e[1]))
                ds.unite(e[0], e[1]);
            else // 入度为 2 的节点，存在回路，优先删除当前边 e
                res = e;
        }
        return res;
    }
};