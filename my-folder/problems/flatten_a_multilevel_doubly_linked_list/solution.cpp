/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head;
        Node *tempHead = new Node(0,NULL,head,NULL);
        solve(tempHead,head);
        tempHead->next->prev = NULL;
        return tempHead->next;
    }
    
    Node* solve(Node *prev, Node* cur) {
        if(cur==NULL) return prev;
        
        cur->prev = prev;
        prev->next = cur;
        
        Node* tempNext = cur->next;
        Node *tail = solve(cur,cur->child);
        cur->child = NULL;
        return solve(tail,tempNext);
    }
};
    