class Node{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val=val;
        next=NULL;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size=0;
    Node *head=new Node(0);
    MyLinkedList() {
    
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i=0;
        if(index>=size||index<0) return -1;
        Node *temp=head->next;
        while(i<index)
        {
            temp=temp->next;
            i++;
        }
        return temp->val;
        
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newhd=head->next;
        head->next=new Node(val);
        head->next->next=newhd;
        size++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *temp=head;
        while(temp->next)temp=temp->next;
        temp->next=new Node(val);
        size++;
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size) return;
            Node *temp=head;
            for(int i=0;i<index;i++)temp=temp->next;
            Node *temp1=temp->next;
            temp->next=new Node(val);
            temp->next->next=temp1;
            size++;
        
        
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index<0||index>=size)return;
        Node *curr=head;
        for(int i=0;i<index;i++)curr=curr->next;
        Node* temp=curr->next;
        curr->next=temp->next;
        size--;
        delete(temp);
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