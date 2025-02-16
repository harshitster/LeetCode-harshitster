/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
        void buildGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
            if(root == nullptr) return;
    
            if(graph.find(root) == graph.end()) {
                graph[root] = vector<TreeNode*>();
            }
    
            if(prev) {
                graph[root].push_back(prev);
                graph[prev].push_back(root);
            }
    
            buildGraph(root -> left, root, graph);
            buildGraph(root -> right, root, graph);
        }
    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            unordered_map<TreeNode*, vector<TreeNode*>> graph;
            buildGraph(root, nullptr, graph);
    
            queue<TreeNode*> q;
            q.push(target);
            set<TreeNode*> st;
            st.insert(target);
    
            while(!q.empty() && k > 0) {
                int size = q.size();
    
                for(int i = 0; i < size; i += 1) {
                    TreeNode* node = q.front();
                    q.pop();
    
                    for(int j = 0; j < graph[node].size(); j += 1) {
                        if(st.find(graph[node][j]) == st.end()) {
                            st.insert(graph[node][j]);
                            q.push(graph[node][j]);
                        }
                    }
                }
                k -= 1;
            }
    
            if(q.empty()) return {};
            
            int size = q.size();
            vector<int> res;
            for(int i = 0; i < size; i += 1) {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node -> val);
            }
            return res;
        }
    };