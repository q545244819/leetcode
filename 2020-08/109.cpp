
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 思路：双指针找到链表中的中间节点，该中间节点作为子树的根节点，该节点前面的所有节点作为左子树，该节点右边的所有节点作为右子树
        TreeNode* root;

        // 处理边界情况
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            root = new TreeNode(head->val);
            return root;
        }

        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;

        // 快慢指针找到中间节点
        // fast 指针走两格
        // slow 指针走一格
        // 当 fast 不能走时，slow 指向就是当前链表的中间节点
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // prev 用于分割 slow 节点之前的节点
        while (prev->next != slow)
            prev = prev->next;
        // 这里等于将 slow 的前一个节点断开与 slow 节点的连接
        prev->next = NULL;
        root = new TreeNode(slow->val);
        // 递归处理左子树
        root->left = sortedListToBST(head);
        // 递归处理右子树
        root->right = sortedListToBST(slow->next);

        return root;
    }
};