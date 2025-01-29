struct Node {
    int val;
    int key;
    Node* next;
    Node* prev;

    Node(int key, int val, Node* next, Node* prev) : key(key), val(val), next(next), prev(prev) {};
};

class LRUCache {
private:
    int capacity;
    Node* head = new Node(-1, -1, nullptr, nullptr);
    Node* tail = new Node(-1, -1, nullptr, nullptr);
    unordered_map<int, Node*> map;

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head -> next = tail;
        tail -> prev = head;
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
            node = new Node(key, value, nullptr, nullptr);
            map[key] = node;
            add(node);
        }

        if(map.size() > capacity) {
            node = tail -> prev;
            remove(node);
            map.erase(node -> key);
        }
    }

    void remove(Node* node) {
        node -> next -> prev = node -> prev;
        node -> prev -> next = node -> next;
    }

    void add(Node* node) {
        Node* head_node = head -> next;
        node -> next = head_node;
        node -> prev = head;
        head_node -> prev = node;
        head -> next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */