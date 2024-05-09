class Solution {
private:
    void helper(TreeNode* root, int k, int* idx, int* flag, int* val) {
        if(*flag == 0) {
            if(root == nullptr) return;

            helper(root -> left, k, idx, flag, val);
            (*idx) += 1;
            if(*idx == k) {
                *val = root -> val;
                *flag = 1;
                return;
            } 
            helper(root -> right, k, idx, flag, val);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int idx = 0, flag = 0, val;
        helper(root, k, &idx, &flag, &val);
        return val;
    }
};