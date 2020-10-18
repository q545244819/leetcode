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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return head;

        ListNode* p1 = head;
        ListNode* p2 = head;
        
        for (int i = 0; i < n; i++)
            p2 = p2->next;
        
        while (p2 != NULL && p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }

        if (p2 == NULL)
            head = p1->next;
        else
            p1->next = p1->next != NULL ? p1->next->next : NULL;

        return head;
    }
};