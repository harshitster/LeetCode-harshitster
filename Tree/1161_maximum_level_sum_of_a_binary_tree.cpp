class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int val = root -> val;
        int max_val = INT_MIN;
        int level = 1;
        int max_level;

        while(!q.empty()) {
            if(val > max_val){
                max_val = val;
                max_level = level;
            }
            val = 0;
            level += 1;
            
            int n = q.size();
            for(int i = 0;  i < n; i += 1) {
                TreeNode* node = q.front();
                q.pop();

                if(node -> left) {
                    q.push(node -> left);
                    val += node -> left -> val;
                } 
                if(node -> right) {
                    q.push(node -> right);
                    val += node -> right -> val;
                }
            }
        }

        return max_level;
    }
};