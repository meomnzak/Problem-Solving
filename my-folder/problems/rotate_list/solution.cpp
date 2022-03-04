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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int sz = 1;
        ListNode *cur = head;
        while(cur->next){
            sz++;
            cur = cur->next;
        }
        ListNode *tail = cur;
        k = k%sz;
        cur = head;
        int go = sz-k;
        for(int i = 1 ; i<go ; i++){
            cur= cur->next;
        }
        tail->next = head;
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};