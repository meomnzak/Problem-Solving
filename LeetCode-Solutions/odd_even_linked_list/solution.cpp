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
        if(head==NULL) 
            return head;
        ListNode *odd = new ListNode();
        ListNode *even = new ListNode();
        ListNode *headOdd = odd;
        ListNode *headEven = even;
        ListNode *cur = head;
        int cnt = 1;
        while(cur){
            ListNode *node = new ListNode(cur->val);
            if(((cnt)%2)==1){
                odd->next = node;
                odd = odd->next;
            }else{
                even->next = node;
                even = even->next;
            }
            cnt++;
            cur = cur->next;
        }
        odd->next = headEven->next;
        return headOdd->next;
    }
};