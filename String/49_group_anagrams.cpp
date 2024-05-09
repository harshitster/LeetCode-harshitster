class Solution {
private:
    void merge(string& s, int left, int pivot, int right) {
        int n1 = pivot - left + 1;
        int n2 = right - pivot;

        vector<char> l;
        vector<char> r;

        for(int i = 0; i < n1; i += 1) {
            l.push_back(s[left + i]);
        }
        for(int i = 0; i < n2; i += 1) {
            r.push_back(s[pivot + 1 + i]);
        }

        int i = 0, j = 0, k = left;
        while(i < n1 && j < n2) {
            if(l[i] <= r[j]) {
                s[k] = l[i++];
            } else {
                s[k] = r[j++];
            }
            k += 1;
        }

        while(i < n1) {
            s[k++] = l[i++];
        }

        while(j < n2) {
            s[k++] = r[j++];
        }
    }

    void mergeSort(string& s, int left, int right) {
        if(left < right) {
            int pivot = left + (right - left) / 2;

            mergeSort(s, left, pivot);
            mergeSort(s, pivot + 1, right);
            merge(s, left, pivot, right);
        }
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for(auto x: strs) {
            string word = x;
            mergeSort(word, 0, word.size() - 1);
            hashmap[word].push_back(x);
        }

        vector<vector<string>> res;
        for(auto& x: hashmap) {
            res.push_back(x.second);
        }

        return res;
    }
};