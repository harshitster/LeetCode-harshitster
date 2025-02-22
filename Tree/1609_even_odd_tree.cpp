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
        bool isEvenOddTree(TreeNode* root) {
            queue<TreeNode*> q;
            q.push(root);
    
            int level = 0;
            while(!q.empty()) {
                int size = q.size();
                int prev = level % 2 == 0 ? -1 : q.front() -> val + 2;
    
                for(int i = 0; i < size; i += 1) {
                    TreeNode* node = q.front();
                    q.pop();
    
                    if(level % 2 == 0 && (node -> val % 2 != 1 || node -> val <= prev)) return false;
                    if(level % 2 == 1 && (node -> val % 2 != 0 || node -> val >= prev)) return false;
    
                    if(node -> left) q.push(node -> left);
                    if(node -> right) q.push(node -> right);
    
                    prev = node -> val;
                }
    
                level += 1;
            }
    
            return true;
        }
    };