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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            int x_found = 0, y_found = 0;
            for(int i = 0; i < n; i += 1) {
                TreeNode* node = q.front();
                q.pop();

                if(node -> left && node -> right) {
                    if(node -> left -> val == x && node -> right -> val == y) return false;
                    else if(node -> left -> val == y && node -> right -> val == x) return false;
                }

                if(node -> left) {
                    q.push(node -> left);
                    if(node -> left -> val == x) x_found = 1; 
                    else if(node -> left -> val == y) y_found = 1;
                }
                if(node -> right) {
                    q.push(node -> right);
                    if(node -> right -> val == y) y_found = 1;
                    else if(node -> right -> val == x) x_found = 1;
                }
            }

            if(x_found == 1 && y_found == 1) return true;
            if(x_found == 1 || y_found == 1) return false;
        }

        return false;
    }
};