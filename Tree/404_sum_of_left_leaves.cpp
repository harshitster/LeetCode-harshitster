class Solution {
private:
    void helper(TreeNode* root, int* sum) {
        if(root == nullptr) return;

        int flag = 0;
        if(root -> left && root -> left -> left == nullptr && root -> left -> right == nullptr) {
            (*sum) += root -> left -> val;
            flag = 1;
        }

        if(flag == 0) helper(root -> left, sum);
        helper(root -> right, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, &sum);
        return sum;
    }
};