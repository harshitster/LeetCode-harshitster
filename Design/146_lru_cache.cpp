struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
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

        return node -> value;
    }
    
    void put(int key, int value) {
        Node* node = nullptr;
        if(map.find(key) != map.end()) {
            node = map[key];
            node -> value = value;
            remove(node);
            add(node);
        } else {
            node = new Node(key, value);
            map[key] = node;
            add(node);
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
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */