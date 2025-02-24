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
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root == nullptr) return nullptr;
    
            if(root -> val > key) root -> left = deleteNode(root -> left, key);
            else if(root -> val < key) root -> right = deleteNode(root -> right, key);
            else {
                if(root -> left == nullptr) return root -> right;
                else if(root -> right == nullptr) return root -> left;
                else {
                    TreeNode* temp = root -> right;
                    while(temp -> left != nullptr) temp = temp -> left;
    
                    int t = root -> val;
                    root -> val = temp -> val;
                    temp -> val = t;
                    root -> right = deleteNode(root -> right, temp -> val);
                }
            }
    
            return root;
        }
    };

// revised - 02/21/2025