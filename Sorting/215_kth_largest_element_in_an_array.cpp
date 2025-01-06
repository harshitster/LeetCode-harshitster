class Solution {
private:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;

        if(left < n && nums[left] >= nums[largest])
            largest = left;
        if(right < n && nums[right] >= nums[largest])
            largest = right;

        if(largest != i) {
            int temp = nums[i];
            nums[i] = nums[largest];
            nums[largest] = temp;

            heapify(nums, n, largest);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i = n/2 - 1; i >= 0; i--)
            heapify(nums, n, i);
        
        for(int i = 1; i < k; i++) {
            nums[0] = nums[n-i];
            heapify(nums, n-i, 0);
        }
        
        return nums[0]; 
    }
};