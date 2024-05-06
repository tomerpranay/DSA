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
class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    ListNode *removeNodes(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *head1 = rev(head);
        ListNode *cur = head1->next;
        ListNode *prev = head1;
        int m = prev->val;
        while (cur != NULL)
        {
            while (cur->next != NULL && cur->val < m)
            {
                cur = cur->next;
            }
            if (m <= cur->val)
            {
                prev->next = cur;
                prev = cur;
                m = cur->val;
            }
            cur = cur->next;
        }
        prev->next = NULL;
        return rev(head1);
    }
};