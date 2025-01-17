class Solution {
private:
    void helper(TreeNode* root, TreeNode** prev, int* flag) {
        if(*flag == 0 || root == nullptr) return;

        helper(root -> left, prev, flag);
        if(*prev != nullptr) {
            if((*prev) -> val >= root -> val) {
                *flag = 0;
                return;
            }
        }
        *prev = root;
        helper(root -> right, prev, flag);
    }
public:
    bool isValidBST(TreeNode* root) {
        int flag = 1;
        TreeNode* prev = nullptr;
        helper(root, &prev, &flag);

        return flag == 1 ? true : false;
    }
};

// Revised - 01/08/2025