class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1, 1);

        for(int i = 1; i <= rowIndex; i += 1) {
            vector<int> temp;
            for(int j = 0; j < i + 1; j += 1) {
                if(j == 0 || j == i) temp.push_back(1);
                else temp.push_back(prev[j - 1] + prev[j]);
            }
            prev = temp;
        }

        return prev;
    }
};

// Needs Optimization