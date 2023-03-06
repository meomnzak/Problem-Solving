struct SinglyListNode{
    int val;
    SinglyListNode *next;
    SinglyListNode(int x){
        val = x;
        next = NULL;
    }
};

struct DoublyListNode{
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};


class MyLinkedList {

private:
   // SinglyListNode *head;
    DoublyListNode *head;
public:
    MyLinkedList() {
        head = NULL;
    }
    
    
//     SinglyListNode *getNode(int index){
//         SinglyListNode *cur = head;
//         for(int i = 0 ; i<index && cur ; i++){
//             cur = cur->next;
//         }
//         return cur;
//     }
    
    DoublyListNode *getNode(int index){
        DoublyListNode *cur = head;
        for(int i = 0 ; i <index && cur ; i++){
            cur = cur->next;
        }
        return cur;
    }
    
//     SinglyListNode *getTail(){
//         SinglyListNode *cur = head;
//         while(cur && cur->next){
//             cur = cur->next;
//         }
//         return cur;
//     }
    
    
    DoublyListNode *getTail(){
        DoublyListNode *cur = head;
        while(cur && cur->next){
            cur = cur->next;
        }
        return cur;
    }
    
    // int get(int index) {
    //     SinglyListNode *cur = getNode(index);
    //     return cur == NULL ? -1 : cur->val;
    // }
    
    int get(int index) {
        DoublyListNode *cur = getNode(index);
        return cur == NULL ? -1 : cur->val;
    }
    
    // void addAtHead(int val) {
    //     SinglyListNode *cur = new SinglyListNode(val);
    //     cur->next = head;
    //     head = cur;
    // }
    
    
    void addAtHead(int val) {
        DoublyListNode *cur = new DoublyListNode(val);
        cur->next = head;
        if(head!=NULL)
            head->prev = cur;
        head = cur;
    }
    
    // void addAtTail(int val) {
    //     if(head==NULL){
    //         addAtHead(val);
    //         return;
    //     }
    //     SinglyListNode *cur = new SinglyListNode(val);
    //     SinglyListNode *prev = getTail();
    //     prev->next = cur;
    // }
    
    
    void addAtTail(int val) {
        if(head==NULL){
            addAtHead(val);
            return;
        }
        DoublyListNode *cur = new DoublyListNode(val);
        DoublyListNode *prev = getTail();
        prev->next = cur;
        cur->prev = prev;
    }
    
//     void addAtIndex(int index, int val) {
//         if(index==0){
//             addAtHead(val);
//             return;
//         }  
//         SinglyListNode *prev = getNode(index-1);
//         if(prev==NULL) return;
//         SinglyListNode *cur = new SinglyListNode(val);
//         SinglyListNode *next = prev->next;
//         prev->next = cur;
//         cur->next = next;
        
//     }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        DoublyListNode *prev = getNode(index-1);
        if(prev==NULL) return;
        DoublyListNode *cur = new DoublyListNode(val);
        DoublyListNode *next = prev->next;
        
        prev->next = cur;
        cur->next = next;
        if(next!=NULL)
            next->prev = cur;
        cur->prev = prev;
    
    }
    
    // void deleteAtIndex(int index) {
    //     SinglyListNode *cur = getNode(index);
    //     if(cur==NULL) return;
    //     SinglyListNode *next = cur->next;
    //     if(index==0){
    //         head = next;
    //     }else{
    //         SinglyListNode *prev = getNode(index-1);
    //         prev->next = next;
    //     }
    // }
    
    
     void deleteAtIndex(int index) {
         DoublyListNode *cur = getNode(index);
         if(cur==NULL) return;
         DoublyListNode *prev = cur->prev;
         DoublyListNode *next = cur->next;
         if(index==0){
             if(next!=NULL)
                next->prev = NULL;
             head = next;
         }else{
             prev->next = next;
             if(next!=NULL)
                next->prev = prev;
         }
         
    }
    
    
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */