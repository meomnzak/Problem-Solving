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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *cur = head;
        int rem = 0;
        while(l1||l2||rem>0){
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;
            int summ = val1+val2+rem;
            rem = summ/10;
            summ%=10;
            ListNode *temp = new ListNode();
            temp->val = summ;
            cur->next = temp;
            cur = temp;
            l1 = (l1) ? l1->next : l1;
            l2 = (l2) ? l2->next : l2;
        }
        return head->next;
    }
};