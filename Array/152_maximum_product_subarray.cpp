class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1, suffix = 1;
        int max_product = INT_MIN;
        int n = nums.size();

        for(int i = 0; i < n; i += 1) {
            if(prefix == 0) {
                prefix = 1;
            }
            if(suffix == 0) {
                suffix = 1;
            }

            prefix *= nums[i];
            suffix *= nums[n - i - 1];

            max_product = max(max_product, max(prefix, suffix));
        }

        return max_product;
    }
};