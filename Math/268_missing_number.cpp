class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maximum = -1;
        int sum = 0;
        int n = nums.size();
        for(int num: nums) {
            sum += num;
            maximum = max(maximum, num);
        }

        int actual_sum = n * (n + 1) / 2;
        return actual_sum - sum;
    }
};