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
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    void helper(TreeNode* root, TreeNode** prev) {
        if(root == nullptr) return;

        helper(root -> left, prev);
        if(*prev != nullptr && (*prev) -> val > root -> val) {
            x = root;
            if(y == nullptr) y = *prev;
        }
        *prev = root;
        helper(root -> right, prev);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        helper(root, &prev);
        
        int temp = x -> val;
        x -> val = y -> val;
        y -> val = temp;
    }
};