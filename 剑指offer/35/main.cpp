/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 分治法
        // 记得空指针一定要初始化为 NULL
        Node* root = NULL;
        Node* point = NULL;
        Node* temp = head;
        
        // 第一步：构造新链表
        // 复制旧链表的所有节点到新节点，且使用 next 连接起来组成一个新到链表
        while (temp != NULL)  {
            Node* p = new Node(temp->val);

            if (root == NULL) {
                point = p;
                root = point;
            } else {
                point->next = p;
                point = point->next;
            }
            
            temp = temp->next;
        }

        // 第二步：处理每一个节点的 random 属性
        temp = head;
        point = root;
        
        while (temp) {
            if (temp->random != NULL) {
                // 1)先从旧链表表头开始查找，直至找到该节点的 radnom 属性对应的节点，并且记录步数 s
                // 注意，查找的比较是两个指针变量比较，而不是值的比较，值可能会出现相同的值，导致查找节点错误
                int s = getDistance(head, temp->random);

                Node* random = root;
                // 2)从新链表表头开始进过 s 个节点，第 s 个节点就是该节点的 radnom 属性对应的节点
                while (s--) random = random->next;

                point->random = random;
            }

            temp = temp->next;
            point = point->next;
        }

        return root;
    }

    int getDistance (Node* head, Node* random) {
        int s = 0;

        while (head != random) {
            head = head->next;
            s++;
        }

        return s;
    }
};