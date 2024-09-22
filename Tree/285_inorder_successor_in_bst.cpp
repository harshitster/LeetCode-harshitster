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
    void helper(TreeNode* root, TreeNode* p, TreeNode** res, int* next) {
        if(*res != nullptr || root == nullptr) return;

        helper(root -> left, p, res, next);
        if(*next) {
            *res = root;
            *next = 0;
            return;
        }
        if(root == p) {
            *next = 1;
        } 
        helper(root -> right, p, res, next);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == p) return root -> right ? root -> right : nullptr;

        TreeNode* res = nullptr;
        int next = 0;
        helper(root, p, &res, &next);

        return res;
    }
};