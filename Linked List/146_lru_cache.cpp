struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {};
};

class LRUCache {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    unordered_map<int, Node*> map;
    int capacity;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;

        Node* node = map[key];
        remove(node);
        add(node);
        return node -> val;
    }
    
    void put(int key, int value) {
        Node* node = nullptr;

        if(map.find(key) != map.end()) {
            node = map[key];
            node -> val = value;
            remove(node);
            add(node);
        } else {
            node = new Node(key, value);
            add(node);
            map[key] = node;
        }

        if(map.size() > capacity) {
            node = tail -> prev;
            remove(node);
            map.erase(node -> key);
        }
    }

    void add(Node* node) {
        Node* head_node = head -> next;
        node -> next = head_node;
        node -> prev = head;
        head_node -> prev = node;
        head -> next = node;
    }

    void remove(Node* node) {
        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 // revised - 02/25/2025