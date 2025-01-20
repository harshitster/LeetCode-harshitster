class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        if(n == k) return arr;

        vector<int> out;

        int left = 0, right = n;
        int pivot;
        while(left < right) {
            pivot = (left + right) / 2;
            if(arr[pivot] >= x) right = pivot;
            else left = pivot + 1;
        }

        left -= 1;
        right = left + 1;
        while(right - left - 1 < k) {
            if(left == -1) right += 1;
            else if(right == n || abs(arr[left] - x) <= abs(arr[right] - x)) left -= 1;
            else right += 1;
        }

        for(int i = left + 1; i < right; i += 1) {
            out.push_back(arr[i]);
        }

        return out;
    }
};