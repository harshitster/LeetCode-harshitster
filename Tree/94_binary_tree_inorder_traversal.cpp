class Solution {
private:
    void helper(vector<int>& inOrder, TreeNode* root) {
        if(root == nullptr) return;

        helper(inOrder, root -> left);
        inOrder.push_back(root -> val);
        helper(inOrder, root -> right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        helper(inOrder, root);
        return inOrder;
    }
};

// Revised - 01/08/2025