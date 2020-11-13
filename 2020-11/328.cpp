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
    ListNode* oddEvenList(ListNode* head) {
        // 思路：双指针
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        
        ListNode* mid = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* n1 = NULL;
        ListNode* n2 = NULL;

        while (odd != NULL && even != NULL) {
            n1 = odd->next ? odd->next->next : odd->next;
            n2 = even->next ? even->next->next : even->next;
            
            if (n1 == NULL)
                break;

            odd->next = n1;
            even->next = n2;
            odd = n1;
            even = n2;
        }

        odd->next = mid;

        return head;
    }
};