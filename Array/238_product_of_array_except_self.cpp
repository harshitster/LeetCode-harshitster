class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> answer(size, 0);

        answer[0] = 1;
        for(int i = 1; i < size; i += 1) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        int right = 1;
        for(int i = size - 1; i >= 0; i -= 1) {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
};