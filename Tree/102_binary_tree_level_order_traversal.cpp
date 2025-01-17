class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);
    
        vector<vector<int>> out;
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i < size; i += 1) {
                TreeNode* node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                temp.push_back(node -> val);
            }
            out.push_back(temp);
        }

        return out;
    }
};

// Revised - 01/08/2025