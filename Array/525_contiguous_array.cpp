class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            int longest = 0, prefix_sum = 0;
            unordered_map<int, int> map;
    
            for(int i = 0; i < nums.size(); i += 1) {
                prefix_sum += (nums[i] == 1) ? 1 : -1;
    
                if(prefix_sum == 0) longest = i + 1;
                else if(map.find(prefix_sum) != map.end()) {
                    longest = max(longest, i - map[prefix_sum]);
                } else map[prefix_sum] = i;
            }
    
            return longest;
        }
    };

// revised - 02/18/2025