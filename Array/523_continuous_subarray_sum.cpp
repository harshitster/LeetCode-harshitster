class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashset;
        hashset[0] = -1;
        int prefix_mod = 0;
        
        for(int i = 0; i < nums.size(); i += 1) {
            prefix_mod = (prefix_mod + nums[i]) % k;
            
            if(hashset.find(prefix_mod) != hashset.end()) {
                if(i - hashset[prefix_mod] > 1) return true;
            } else {
                hashset[prefix_mod] = i;   
            }
        }
        
        return false;
    }
};