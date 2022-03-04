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
    bool isPalindrome(ListNode* head) {
        ListNode *go = head;
        int sz = 1;
        while(go->next != NULL){
            go = go->next;
            sz++;
        }
        if(sz==1) return true;
        ListNode *cur = head;
        for(int i = 1 ; i<sz/2 ; i++){
            cur = cur->next;
        }
        
        if(sz%2==0){
            cur = cur->next;
        }else{
            cur = cur->next->next;
        }
        ListNode *newHead  = new ListNode(cur->val);
        ListNode *newCur = newHead;
        cur = cur->next;
        while(cur != NULL){
            ListNode *temp = new ListNode(cur->val);
            newCur->next = temp;
            newCur = newCur->next;
            cur = cur->next;
        }
        
        ListNode *curHead = newHead;
        while(newHead->next != NULL){
            ListNode *p = newHead->next;
            newHead->next = p->next;
            p->next = curHead;
            curHead = p;
        }
        
        ListNode *first = head;
        ListNode *second = curHead;
        for(int i = 0 ; i<sz/2 ; i++){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
        
    }
};