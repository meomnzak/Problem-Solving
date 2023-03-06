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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *,int> mp;
        while(headA != NULL){
            mp[headA] = 1;
            headA = headA->next;
        }
        bool flag = false;
        while(headB != NULL){
            if(mp.find(headB)!=mp.end()){
                return headB;   
            }
            mp[headB] = 1;
            headB = headB->next;
        }
        return NULL;
    }
};