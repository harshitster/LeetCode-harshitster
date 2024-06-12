class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[] = {0, 0, 0};

        for(int num: nums) {
            count[num] += 1;
        }

        int left = 0;
        for(int i = 0; i <= 2; i += 1) {
            for(int j = 0; j < count[i]; j += 1) {
                nums[left++] = i;
            }
        }
    }
};