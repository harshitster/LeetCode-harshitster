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
class Solution {
private:
    void helper(TreeNode* root, double target, vector<pair<double, int>>& h) {
        if(root == nullptr) return;

        h.push_back({abs(root -> val - target), root -> val});
        helper(root -> left, target, h);
        helper(root -> right, target, h);
    }
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<pair<double, int>> h;
        vector<int> result;

        helper(root, target, h);

        make_heap(h.begin(), h.end(), greater<pair<double, int>>());
        for(int i = 0; i < k; i += 1) {
            pop_heap(h.begin(), h.end(), greater<pair<double, int>>());
            result.push_back(h.back().second);
            h.pop_back();
        }

        return result;
    }
};