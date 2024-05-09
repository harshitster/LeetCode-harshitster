class Solution {
private:
    bool isValid(int x, int y, int rows, int cols) {
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }
    void dfs(vector<vector<char>>& grid, int x, int y, int rows, int cols) {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; d += 1) {
            int xd = x + dx[d];
            int yd = y + dy[d];

            if(isValid(xd, yd, rows, cols) && grid[xd][yd] == '1') {
                grid[xd][yd] = '0';
                dfs(grid, xd, yd, rows, cols);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        for(int i = 0; i < rows; i += 1) {
            for(int j = 0; j < cols; j += 1) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, rows, cols);
                    count += 1;
                }
            }
        }

        return count;
    }
};