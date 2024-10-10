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
    void helper(TreeNode* root, string& s) {
        if(root == nullptr) return;

        s += to_string(root -> val);

        if(root -> left == nullptr && root -> right == nullptr) return;
        s += "(";
        helper(root -> left, s);
        s += ")";
        if(root -> right) {
            s += "(";
            helper(root -> right, s);
            s += ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        string s = "";
        helper(root, s);
        return s;
    }
};