class Solution {
private:
    TreeNode* helper(TreeNode* root, vector<TreeNode*>& res, unordered_map<int, int>& map) {
        if(root == nullptr) return nullptr;

        root -> left = helper(root -> left, res, map);
        root -> right = helper(root -> right, res, map);

        if(map.find(root -> val) != map.end()) {
            if(root -> left != nullptr || root -> right != nullptr) {
                if(root -> left) res.push_back(root -> left);
                if(root -> right) res.push_back(root -> right);
            }
            return nullptr;
        }

        return root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == nullptr) return {};

        unordered_map<int, int> map;
        for(int d: to_delete) map[d] = 1;

        vector<TreeNode*> res;
        if(helper(root, res, map)) res.push_back(root);

        return res;
    }
};