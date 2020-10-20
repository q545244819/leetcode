/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // 思路：模拟重排过程，总的操作次数是链表节点数量的一半
        // 当前 i 节点连接到 n - i 节点，且暂存之前 i 节点的 next 指针，最后将 n - i 的 next 赋值为之前保存的 next 节点
        // 最后当前节点设置为暂存的 next 节点，重复以上步骤
        if (head == NULL)
            return;

        stack<ListNode*> S;
        
        for (ListNode* node = head; node != NULL; node = node->next)
            S.push(node);
        
        ListNode* h = head;
        int cnt = S.size() / 2;
        
        while (cnt--) {
            ListNode* next = h->next;
            h->next = S.top(); S.pop();
            h->next->next = next;
            h = next;
        }

        h->next = NULL;
    }
};