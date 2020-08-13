/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, bool> visited;
    map<int, Node*> memo;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;

        Node* u = new Node(node->val);
            
        memo[u->val] = u;
        visited[u->val] = true;

        for (Node* v : node->neighbors) {
            if (!visited[v->val])
                u->neighbors.push_back(cloneGraph(v));
            else
                u->neighbors.push_back(memo[v->val]);
        }

        return u;
    }
};