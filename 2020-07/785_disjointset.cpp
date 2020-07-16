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
    bool isBipartite(vector<vector<int>>& graph) {
        DisjointSet ds = DisjointSet(graph.size());

        for (int v = 0; v < graph.size(); v++) {
            for (int u: graph[v]) {
                if (ds.same(v, u)) {
                    return false;
                }
                ds.unite(graph[v][0], u);
            }
        }

        return true;
    }
};