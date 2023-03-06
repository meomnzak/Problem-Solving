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
        ListNode *cur = head;
        int cnt = 0;
        while(cur){
            cur = cur->next;
            cnt++;
        }
        int idx = cnt-n+1;
  //      cout<<cnt<<" "<<idx<<endl;
        if(idx==1){
            head = head->next;
        }else{
            ListNode *prev = head;
            for(int i = 0 ; i<idx-2 ; i++){
                prev = prev->next;
            }
            cur = prev->next;
            ListNode *next= cur->next;
       //     cout<<prev->val<<" "<<cur->val<<" "<<next->val<<endl;
            prev->next = next;
        }
        return head;
    }
};