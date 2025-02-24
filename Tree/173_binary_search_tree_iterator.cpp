/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* prev = new TreeNode(-1);
    TreeNode* node = prev;
    void helper(TreeNode* root, TreeNode** prev) {
        if(root == nullptr) return;

        helper(root -> left, prev);
        (*prev) -> right = root;
        *prev = root;
        helper(root -> right, prev);
    }
public:
    BSTIterator(TreeNode* root) {
        helper(root, &prev);
    }
    
    int next() {
        node = node -> right;
        return node -> val;
    }
    
    bool hasNext() {
        if(node -> right) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */