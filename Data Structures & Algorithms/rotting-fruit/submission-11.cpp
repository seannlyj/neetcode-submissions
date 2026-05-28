class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int x, int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    int orangesRotting(vector<vector<int>>& grid) {
        //multi-source bfs
        vector<pair<int, int>> neighborOffset = {{1 ,0}, {-1,0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;

        // get all rotting fruits
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){ 
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int minutes = 0;
        while(!q.empty()){
            int levelSize = q.size();
            
            //process all current rotten fruits at this level
            for(int i = 0; i < levelSize; i++){
                pair<int, int> pos = q.front();
                q.pop();

                for(auto& posOffset: neighborOffset){ 
                    int nx = pos.first + posOffset.first;
                    int ny = pos.second + posOffset.second;
                    
                    if(isValid(grid, nx, ny)) {
                        if(grid[nx][ny] == 1 && !visited[nx][ny]){
                            grid[nx][ny] = 2;
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }

            if(!q.empty()){
                minutes++;
            }
        }

        // check if there are any more normal fruits
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minutes;
    }
};
