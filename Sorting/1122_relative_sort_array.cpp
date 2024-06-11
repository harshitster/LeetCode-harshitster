class Solution {
private:
    void heapify(vector<int>& arr, int n, int i) {
        int smallest = i;
        int left = 2 * smallest + 1;
        int right = 2 * smallest + 2;

        if(left < n && arr[smallest] > arr[left]) smallest = left;
        if(right < n && arr[smallest] > arr[right]) smallest = right;

        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int left = -1, right;
        int n1 = arr1.size(), n2 = arr2.size();

        for(int i = 0; i < n2; i += 1) {
            right = left + 1;

            while(right < arr1.size()) {
                if(arr1[right] == arr2[i]) {
                    left += 1;
                    if(left != right) {
                        swap(arr1[left], arr1[right]);
                    }
                } 
                right += 1;
            }
        }

        if(left < n1 - 1) {
            left += 1;

            vector<int> temp;
            int size = n1 - left;
            for(int i = left; i < n1; i += 1) {
                temp.push_back(arr1[i]);
            }

            for(int i = size / 2; i >= 0; i -= 1) {
                heapify(temp, size, i);
            }

            for(int i = size - 1; i > 0; i -= 1) {
                swap(temp[i], temp[0]);
                arr1[left++] = temp[i];

                heapify(temp, i, 0);
            }
            arr1[left] = temp[0];
        }

        return arr1;
    }
};