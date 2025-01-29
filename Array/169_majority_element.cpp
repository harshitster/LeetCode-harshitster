class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 1, n = nums.size(), num = nums[0];
        for(int i = 1; i < n; i += 1) {
            if(num == nums[i]) {
                counter += 1;
            } else {
                counter -= 1;
                if(counter == -1) {
                    num = nums[i];
                    counter = 1;
                }
            }
        }

        return num;        
    }
};

// revised - 01/27/2025