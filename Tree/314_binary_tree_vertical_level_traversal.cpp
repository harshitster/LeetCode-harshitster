class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;

        map<int, vector<int>> hashmap;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                auto [node, col] = q.front();
                q.pop();

                hashmap[col].push_back(node->val);
                
                if(node->left) q.push({node->left, col - 1});
                if(node->right) q.push({node->right, col + 1});
            }
        }

        for(const auto& pair : hashmap) {
            res.push_back(pair.second);
        }

        return res;
    }
};