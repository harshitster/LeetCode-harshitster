/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void buildGraph(TreeNode* root, unordered_map<int, vector<int>>& graph, TreeNode* prev) {
        if(root == nullptr) return;

        if(graph.find(root->val) == graph.end()) {
            graph[root->val] = vector<int>();
        }
    
        if(prev != nullptr) {
            graph[prev -> val].push_back(root -> val);
            graph[root -> val].push_back(prev -> val);
        }

        buildGraph(root -> left, graph, root);
        buildGraph(root -> right, graph, root);
    }

    int bfs(unordered_map<int, vector<int>> graph, int start) {
        queue<int> q;
        q.push(start);
        set<int> visited;
        visited.insert(start);

        int time = -1;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i += 1) {
                int node = q.front();
                q.pop();

                for(int ne: graph[node]) {
                    if(visited.find(ne) == visited.end()) {
                        q.push(ne);
                        visited.insert(ne);
                    }
                }
            }
            time += 1;
        }

        return time;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> graph;
        buildGraph(root, graph, nullptr);

        return bfs(graph, start);
    }
};