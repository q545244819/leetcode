/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode* cur = head;
        int arranged = 0;
    
        if (cur == NULL)
            return head;
        
        while (cur) {
            ListNode* next = cur->next;
            ListNode* prev = NULL;
            ListNode* node = head;
            bool inserted = false;

            cur->next = NULL;

            for (int i = 0; i < arranged; i++) {
                if (cur->val < node->val) {
                    // 插入头部
                    if (prev == NULL) {
                        cur->next = head;
                        head = cur;
                    } else {
                        prev->next = cur;
                        cur->next = node;
                    }
                    inserted = true;
                    break;
                }

                prev = node;
                node = node->next;
            }
            
            // 前面的数都比当前的数小，所以不需要新插入，而是调整前一个结点的 next 指向
            if (!inserted && arranged)
                prev->next = cur;

            cur = next;
            arranged++;
        }
        
        return head;
    }
};