class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> map(201, 0);
        vector<vector<int>> res;
        int size = 0;

        for(int num: nums) {
            if(map[num] >= size) {
                res.push_back(vector<int>());
                size += 1;
            }

            res[map[num]].push_back(num);
            map[num] += 1;
        }

        return res;
    }
};