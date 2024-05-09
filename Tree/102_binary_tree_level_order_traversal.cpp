class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) {
            return res;
        }

        queue<TreeNode*> bfs_queue;
        bfs_queue.push(root);

        while(!bfs_queue.empty()){
            int size = bfs_queue.size();
            vector<int> temp;

            for(int i = 0; i < size; i += 1) {
                TreeNode* front = bfs_queue.front();
                bfs_queue.pop();

                if(front -> left) bfs_queue.push(front -> left);
                if(front -> right) bfs_queue.push(front -> right);

                temp.push_back(front -> val);
            }

            res.push_back(temp);
        }
        return res;
    }
};