/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        Node *newHead = new Node(-1);
        Node *newCur = newHead;
        Node *cur = head;
        unordered_map<Node *, Node *> mp;
        while(cur){
            Node *temp = new Node(cur->val);
            newCur->next = temp;
            newCur = temp;
            mp[cur] = newCur;
            cur = cur->next;
        }
        newHead = newHead->next;
        cur = head;
        newCur = newHead;
        while(cur){
            newCur->random = mp[cur->random];
            newCur = newCur->next;
            cur = cur->next;
        }
        return newHead;
    }
};