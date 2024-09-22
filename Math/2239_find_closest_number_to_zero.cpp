class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min_abs = INT_MAX;
        int value;

        for(auto num: nums) {
            if(abs(num) < min_abs) {
                min_abs = abs(num);
                value = num;
            } else if(abs(num) == min_abs) {
                value = max(value, num);
            }
        }   

        return value;
    }
};