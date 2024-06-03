class Solution {
private:
    void helper(TreeNode* root, vector<string>& res, vector<int>& temp) {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr) {
            string e;
            for (int i = 0; i < temp.size(); i++) {
                e += to_string(temp[i]);
                e += "->";
            }
            e += to_string(root->val);
            res.push_back(e);
            return;
        }

        temp.push_back(root->val);
        helper(root->left, res, temp);
        helper(root->right, res, temp);
        temp.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp;
        vector<string> res;
        helper(root, res, temp);

        return res;
    }
};
Explanatio