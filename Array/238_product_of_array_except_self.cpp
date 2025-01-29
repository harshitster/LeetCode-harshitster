class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> postfix(n);

        prefix[0] = 1;
        postfix[n - 1] = 1;

        for(int i = 1; i < n; i += 1) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            postfix[n - i - 1] = postfix[n - i] * nums[n - i];
        }

        for(int i = 0; i < n; i += 1) nums[i] = prefix[i] * postfix[i];
        return nums;
    }
};

// revised - 01/28/2025