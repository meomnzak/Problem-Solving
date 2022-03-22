/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        // ImmutableListNode* oldHead = head;
        // ImmutableListNode* curHead = head;
        // while(oldHead->next){
        //     ImmutableListNode* p = oldHead->next;
        //     oldHead->next = p->next;
        //     p->next = curHead;
        //     curHead = p;
        // }
        ImmutableListNode* cur = head;
        solve(cur);
    }
    void solve(ImmutableListNode* cur){
        if(cur==NULL) return;
        solve(cur->getNext());
        cur->printValue();
    }
};