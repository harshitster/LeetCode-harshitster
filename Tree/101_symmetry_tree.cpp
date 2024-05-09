class Solution {
private:
    bool helper(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;

        if(left -> val != right -> val) return false;

        bool l = helper(left -> left, right -> right);
        bool r = helper(left -> right, right -> left);
        
        return l && r;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return helper(root -> left, root -> right);
    }
};