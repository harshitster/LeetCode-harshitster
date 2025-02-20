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
        void helper(TreeNode* root, TreeNode** prev, TreeNode** x, TreeNode** y) {
            if(root == nullptr) return;
    
            helper(root -> left, prev, x, y);
            if(*prev && (*prev) -> val >= root -> val) {
                if(*x == nullptr) *x = *prev;
                *y = root;
            }
            *prev = root;
            helper(root -> right, prev, x, y);
        }
    public:
        void recoverTree(TreeNode* root) {
            TreeNode* prev = nullptr;
            TreeNode* x = nullptr, *y = nullptr;
            helper(root, &prev, &x, &y);
    
            int temp = x -> val;
            x -> val = y -> val;
            y -> val = temp;
        }
    };

// revised - 02/19/2025