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
class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this -> minNode = minNode;
        this -> maxNode = maxNode;
        this -> maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue helper(TreeNode* root) {
        if(root == nullptr) return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = helper(root -> left);
        auto right = helper(root -> right);

        if(left.maxNode < root -> val && right.minNode > root -> val) {
            return NodeValue(
                min(left.minNode, root -> val), 
                max(right.maxNode, root -> val), 
                left.maxSize + right.maxSize + 1
            );
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root).maxSize;
    }
};