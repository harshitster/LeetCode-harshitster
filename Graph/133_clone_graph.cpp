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
        Node* dfs(Node* node, unordered_map<Node*, Node*>& map) {
            if(map.find(node) != map.end()) {
                return map[node];
            }
    
            Node* head = new Node(node->val);
            map[node] = head; 
    
            for(Node* neighbor : node->neighbors) {
                head->neighbors.push_back(dfs(neighbor, map));
            }
    
            return head;
        }
    public:
        Node* cloneGraph(Node* node) {
            if(!node) return nullptr;
            unordered_map<Node*, Node*> visited;
            return dfs(node, visited);
        }
    };