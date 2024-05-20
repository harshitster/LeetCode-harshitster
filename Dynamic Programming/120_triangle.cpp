class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n_rows = triangle.size();
        if(n_rows <= 1) {
            return triangle[0][0];
        }
        int n = triangle[n_rows - 2].size();

        for(int i = n_rows - 2; i >= 0; i -= 1) {
            for(int j = 0; j < n; j += 1) {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
            n -= 1;
        }

        return triangle[0][0];
    }
};