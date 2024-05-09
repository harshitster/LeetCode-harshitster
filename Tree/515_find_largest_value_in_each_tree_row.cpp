class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        root -> left = deleteNode(root -> left, key);
        root -> right = deleteNode(root -> right, key);
        if(root -> val == key) {
            if(root -> left == nullptr) return root -> right;
            else if(root -> right == nullptr) return root -> left;
            else {
                TreeNode* temp = root -> right;
                while(temp -> left) temp = temp -> left;

                root -> val = temp -> val;
                root -> right = deleteNode(root -> right, temp -> val);
            }
        }

        return root;
    }
};