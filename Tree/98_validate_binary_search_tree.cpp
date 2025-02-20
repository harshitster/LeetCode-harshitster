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
        void helper(TreeNode* root, TreeNode** prev, int* flag) {
            if(root == nullptr || *flag == 0) return;
    
            helper(root -> left, prev, flag);
            if((*prev) && (*prev) -> val >= root -> val) *flag = 0;
            (*prev) = root;
            helper(root -> right, prev, flag);
        }
    public:
        bool isValidBST(TreeNode* root) {
            int flag = 1;  
            TreeNode* prev = nullptr;
            helper(root, &prev, &flag);
    
            return flag == 1;
        }
    };

// revised - 02/19/2025