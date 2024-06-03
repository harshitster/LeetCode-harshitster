class Solution {
private:
    void helper(TreeNode* root, int targetSum, int* count, long long sum, unordered_map<long long, int>& s) {
        if(root == nullptr) return;

        sum += root -> val;
        if(sum == targetSum) (*count) += 1;
        
        if(s.find(sum - targetSum) != s.end()) (*count) += s[sum - targetSum];

        if(s.find(sum) == s.end()) s[sum] = 1;
        else s[sum] += 1;

        helper(root -> left, targetSum, count, sum, s);
        helper(root -> right, targetSum, count, sum, s);

        s[sum] -= 1;
        if(s[sum] == 0) s.erase(sum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long, int> s;
        helper(root, targetSum, &count, 0, s);
        return count;
    }
};