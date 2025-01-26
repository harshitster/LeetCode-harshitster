class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1_copy;
        for(int i = 0; i < m; i += 1) nums1_copy.push_back(nums1[i]);

        int i = 0, j = 0, k = 0;
        while(i < m && j < n) {
            if(nums1_copy[i] <= nums2[j]) nums1[k++] = nums1_copy[i++];
            else nums1[k++] = nums2[j++];
        }

        while(i < m) nums1[k++] = nums1_copy[i++];
        while(j < n) nums1[k++] = nums2[j++];
    }
};