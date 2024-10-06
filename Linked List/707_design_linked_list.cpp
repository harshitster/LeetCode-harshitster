class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this -> val = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

class MyLinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
public:
    MyLinkedList() {
        this -> head = new Node(-1);
        this -> tail = new Node(-1);
        this -> head -> next = tail;
        this -> tail -> prev = head;

        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;

        Node* temp = head -> next;
        for(int i = 0; i != index; i += 1) {
            temp = temp -> next;
        }
        return temp -> val;
    }
    
    void addAtHead(int val) {
        Node* node = new Node(val);
        node -> next = head -> next;
        node -> next -> prev = node;
        head -> next = node;
        node -> prev = head;
        size += 1;
    }
    
    void addAtTail(int val) {
        Node* node = new Node(val);
        node -> prev = tail -> prev;
        node -> prev -> next = node;
        tail -> prev = node;
        node -> next = tail;
        size += 1;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        else if(index == size) {
            addAtTail(val);
        } else {
            Node* temp = head -> next;
            for(int i = 0; i != index; i += 1) {
                temp = temp -> next;
            }

            Node* prev = temp -> prev;
            Node* node = new Node(val);

            node -> next = temp;
            node -> prev = prev;
            temp -> prev = node;
            prev -> next = node;
            size += 1;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        Node* node = head -> next;
        for(int i = 0; i != index; i += 1) {
            node = node -> next;
        }

        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;
        node -> next = nullptr;
        node -> prev = nullptr;
        delete node;
        size -= 1;
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