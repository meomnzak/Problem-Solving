/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *node = new Node(insertVal);
        if(head==NULL){
            head = node;
            node->next = head;
            return head;
        }
        int cnt = 5e4+7;
        Node *prev = head;
        Node *cur = prev->next;
        Node *mini = new Node(1e9);
        Node *maxi = cur;
        while(cnt--){
            if(insertVal>=prev->val && insertVal<=cur->val ){
                prev->next = node;
                node->next = cur;
                return head;
            }
            if(prev->val >= maxi->val && prev->val>cur->val){
                maxi = prev;
            }
            prev = prev->next;
            cur = cur->next;
        }
        mini = maxi->next;
        maxi->next = node;
        node->next = mini;
      
        return head;
        
    }
};