class Solution {
private:
    void helper(TreeNode* root, vector<int>& res, int* max_right, int right) {
        if(root == nullptr) return;

        if(right > *max_right) {
            res.push_back(root -> val);
            *max_right = right;
        }

        helper(root -> right, res, max_right, right + 1);
        helper(root -> left, res, max_right, right + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        int max_right = 0;
        vector<int> res;

        helper(root, res, &max_right, 1);

        return res;
    }
};