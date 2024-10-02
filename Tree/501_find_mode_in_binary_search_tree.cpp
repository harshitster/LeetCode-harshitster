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
    void helper(TreeNode* root, unordered_map<int, int>& map, vector<int>& res, int* mode) {
        if(root == nullptr) return;

        if(map.find(root -> val) == map.end()) {
            map[root -> val] = 1;
        } else {
            map[root -> val] += 1;
        }

        if(map[root -> val] > *mode) {
            res = {};
            res.push_back(root -> val);
            *mode = map[root -> val];
        } else if(map[root -> val] == *mode) {
            res.push_back(root -> val);
        }

        helper(root -> left, map, res, mode);
        helper(root -> right, map, res, mode);
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> res;
        int mode = 0;

        helper(root, map, res, &mode);

        return res;
    }
};