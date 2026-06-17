class Solution {
public:
    bool isValid(vector<vector<char>>& grid, int x, int y){

        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    void dfs(vector<vector<char>>& grid, vector<pair<int, int>> neighbours, int x, int y){
        if(grid[x][y] == '0') return;

        grid[x][y] = '0';

        for(auto &[offsetX, offsetY] : neighbours){
            if(isValid(grid, x + offsetX, y + offsetY)) dfs(grid, neighbours, x + offsetX, y + offsetY);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int maxIslands = 0;

        vector<pair<int, int>> neighbours = {{1,0}, {-1,0}, {0,1}, {0, -1}};

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    maxIslands++;
                    dfs(grid, neighbours, i, j);
                }
            }
        }

        return maxIslands;
    }
};
