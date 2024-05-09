class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && nums[left] > nums[i]) largest = left;
        if(right < n && nums[right] > nums[largest]) largest = right;

        if(largest != i) {
            swap(nums, largest, i);
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums) {
        int n = nums.size();

        for(int i = n / 2; i >= 0; i -= 1) heapify(nums, n, i);

        for(int i = n - 1; i >= 0; i -= 1) {
            swap(nums, 0, i);
            heapify(nums, i, 0);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums);
        return nums[nums.size() - k];
    }
};