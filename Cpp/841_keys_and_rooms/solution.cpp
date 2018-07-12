class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> opened(rooms.size(), false);
        dfs(rooms, opened, 0);
        for (int i = 0; i < opened.size(); i ++) {
            if (!opened[i]) return false;
        }
        return true;
    }
    
    void dfs(vector<vector<int>>& rooms,vector<bool>& opened, int num) {
        if (opened[num]) return;
        opened[num] = true;
        for (int key : rooms[num]) 
            dfs(rooms, opened, key);
    }
};