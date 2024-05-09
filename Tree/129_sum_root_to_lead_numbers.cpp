class Solution {
private:
    void helper(TreeNode* root, int* sum, int run_sum) {
        if(root == nullptr) return;

        run_sum = run_sum * 10 + root -> val;

        if(root -> left == nullptr && root -> right == nullptr) {
            *sum += run_sum;
            return;
        }

        helper(root -> left, sum, run_sum);
        helper(root -> right, sum, run_sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;

        int sum = 0;
        helper(root, &sum, 0);
        return sum;
    }
};