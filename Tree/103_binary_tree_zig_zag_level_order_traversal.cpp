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
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(root == nullptr) return {};
    
            queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> out;
    
            int left = 1;
            while(!q.empty()) {
                int size = q.size();
                vector<int> temp(size);
    
                for(int i = 0; i < size; i += 1) {
                    TreeNode* node = q.front();
                    q.pop();
    
                    int index = left ? i : size - i - 1;
                    temp[index] = node -> val;
    
                    if(node -> left) q.push(node -> left);
                    if(node -> right) q.push(node -> right);
                }
    
                out.push_back(temp);
                left = 1 - left;
            }
    
            return out;
        }
    };

// revised - 02/19/2025