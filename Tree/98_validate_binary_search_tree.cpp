class Solution {
private:
    void helper(TreeNode* root, long int* prev, int* flag) {
        if(*flag == 1) {
            if(root == nullptr) return;

            helper(root -> left, prev, flag);
            if(root -> val <= *prev){
                *flag = 0;
                return;
            }
            *prev = root -> val;
            helper(root -> right, prev, flag);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        long int prev = LONG_MIN; 
        int flag = 1;
        helper(root, &prev, &flag);
        return flag == 1;
    }
};