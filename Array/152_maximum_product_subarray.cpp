class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int prefix = 1, suffix = 1, max_product = INT_MIN;
    
            for(int i = 0; i < nums.size(); i += 1) {
                if(prefix == 0) prefix = 1;
                if(suffix == 0) suffix = 1;
    
                prefix *= nums[i];
                suffix *= nums[nums.size() - 1 - i];
    
                max_product = max(max_product, max(suffix, prefix));
            }
    
            return max_product;
        }
    };

// revised - 02/25/2025