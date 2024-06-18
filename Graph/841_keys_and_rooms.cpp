class Solution {
private:
    void dfs(vector<vector<int>>& rooms, int source, int n_rooms, vector<int>& visited) {
        visited[source] = 1;

        for(int i = 0; i < rooms[source].size(); i += 1) {
            if(visited[rooms[source][i]] == 0) dfs(rooms, rooms[source][i], n_rooms, visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n_rooms = rooms.size();
        vector<int> visited (n_rooms, 0);

        dfs(rooms, 0, n_rooms, visited);

        for(int i = 0; i < n_rooms; i += 1) {
            if(visited[i] == 0) return false;
        }

        return true;
    }
};