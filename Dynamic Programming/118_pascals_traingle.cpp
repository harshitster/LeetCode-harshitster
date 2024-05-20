class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for(int i = 0; i < numRows; i += 1) {
            vector<int> temp;
            for(int j = 0; j < i + 1; j += 1) {
                if(j == 0 || j == i) {
                    temp.push_back(1);
                } else {
                    temp.push_back(res[i - 1][j - 1] + res[i - 1][j]);
                }
            }
            res.push_back(temp);
        }

        return res;
    }
};