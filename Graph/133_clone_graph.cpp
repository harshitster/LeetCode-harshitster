/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    private:
        void dfs(Node* node, unordered_map<Node*, Node*>& map, set<Node*>& visited) {
            visited.insert(node);
    
            map[node] = new Node(node -> val);
            for(Node* n: node -> neighbors) {
                if(visited.find(n) == visited.end()) {
                    dfs(n, map, visited);
                }
                map[node] -> neighbors.push_back(map[n]);
            }
        }
    public:
        Node* cloneGraph(Node* node) {
            if(node == nullptr) return nullptr;
    
            unordered_map<Node*, Node*> map;
            set<Node*> visited;
            dfs(node, map, visited);
    
            return map[node];
        }
    };

// revised - 02/25/2025