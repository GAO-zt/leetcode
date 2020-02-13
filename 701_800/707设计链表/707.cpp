class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct ListNode {
        int val;
        ListNode *prev;
        ListNode *next;          
        ListNode(int x): val(x), prev(nullptr), next(nullptr) {}
    }; 
    
    ListNode *head;
    ListNode *tail;      
    int size;    
 
    MyLinkedList() {      
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void print_val() {
        // ListNode *p = head->next;
        // printf("p->val = ");    
        // for(int i=0;i<size;i++) {
        //     printf("%d, ", p->val);
        //     p = p->next;
        // }
        // printf("\n");
    }
    
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index > size) return -1;
        ListNode *p = head->next;
        for(int i=0; i<index; i++) {
            p = p->next;
        }
        return p->val;        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode *p_add = new ListNode(val);
        p_add->prev = head;        
        p_add->next = head->next;    
        head->next->prev = p_add;
        head->next = p_add;
        size++;
        print_val();
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *p_add = new ListNode(val);
        p_add->next = tail;
        p_add->prev = tail->prev;
        tail->prev->next = p_add;
        tail->prev = p_add;
        size++;
        print_val();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0) {
            addAtHead(val);
        }
        else if(index < size){
            ListNode *p_add = new ListNode(val);
            ListNode *find = head;
            for(int i=0;i<index;i++) {
                find = find->next;        
            }
            p_add->next = find->next;
            p_add->prev = find;
            find->next->prev = p_add;
            find->next = p_add;
            size++;                  
        }                 
        else if(index == size) {
            addAtTail(val); 
        }
        ListNode *p = head->next;
        print_val();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= 0 && index < size) {
            ListNode *p = head;
            for(int i=0;i < index;i++) {
                p = p->next;
            }
            // printf("p->val = %d\n", p->val); 
            ListNode *p_del = p->next;
            p->next->next->prev = p;
            p->next = p->next->next;
            p_del->next = nullptr;
            p_del->prev = nullptr;
            size--;
            print_val();
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