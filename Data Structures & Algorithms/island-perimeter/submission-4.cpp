class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int x, int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int startX, int startY){
        vector<pair<int, int>> neighbors = {{1,0}, {0,1}, {-1,0}, {0,-1}};

        stack<pair<int, int>> s;
        s.push({startX, startY});
        visited[startX][startY] = true;

        int result = 0;

        while(!s.empty()){
            int x = s.top().first;
            int y = s.top().second;
            s.pop();

            int sides = 4;
            for(auto neighbor : neighbors){
                int nX = x + neighbor.first;
                int nY = y + neighbor.second;
                if(isValid(grid, nX, nY) && grid[nX][nY] == 1){
                    sides--;

                    if(!visited[nX][nY]){
                        s.push({nX, nY});
                        visited[nX][nY] = true;
                    }
                }
            }

            result += sides;
        }

        return result;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        //dfs
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return dfs(grid, visited, i, j);
                }
            }
        }

        return 0;
    }
};