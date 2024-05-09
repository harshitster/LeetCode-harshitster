class Solution {
private:
    void helper(TreeNode* root, vector<vector<int>>& res, vector<int> element, int targetSum, int run_sum) {
        if(root == nullptr) return;

        element.push_back(root -> val);
        if(root -> left == nullptr && root -> right == nullptr) {
            if(run_sum + root -> val == targetSum) {
                vector<int> temp;
                for(int i = 0; i < element.size(); i += 1) {
                    temp.push_back(element[i]);
                }
                res.push_back(temp);
            } 
        }

        helper(root -> left, res, element, targetSum, run_sum + root -> val);
        helper(root -> right, res, element, targetSum, run_sum + root -> val);
        element.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> element;

        helper(root, res, element, targetSum, 0);
        return res;
    }
};