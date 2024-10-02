class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int max_width = 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left_index = q.front().second;  
            unsigned long long right_index = 0;

            for (int i = 0; i < size; ++i) {
                pair<TreeNode*, unsigned long long> p = q.front();
                q.pop();
                unsigned long long current_index = p.second - left_index; 
                right_index = current_index;

                if (p.first->left) q.push({p.first->left, 2 * current_index});
                if (p.first->right) q.push({p.first->right, 2 * current_index + 1});
            }

            max_width = max(max_width, static_cast<int>(right_index + 1));
        }

        return max_width;
    }
};
