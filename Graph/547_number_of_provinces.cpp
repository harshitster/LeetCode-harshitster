class Solution {
private:
    void helper(vector<vector<int>>& isConnected, int source, int n, vector<int>& visited) {
        visited[source] = 1;

        for(int i = 0; i < n; i += 1) {
            if(isConnected[source][i] == 1 && visited[i] == 0) {
                helper(isConnected, i, n, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited (n, 0);
        int count = 0;
        
        for(int i = 0; i < n; i += 1) {
            if(visited[i] == 0) {
                helper(isConnected, i, n, visited);
                count += 1;
            }
        }

        return count;
    }
};