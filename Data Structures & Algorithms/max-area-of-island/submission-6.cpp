class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int x, int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    int bfs(vector<vector<int>>& grid, int startingX, int startingY){
        int islandMaxArea = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        queue<array<int, 2>> q;
        q.push({startingX, startingY});
        visited[startingX][startingY] = true;

        while(!q.empty()){
            array<int, 2> pos = q.front();
            q.pop();

            if(grid[pos[0]][pos[1]] == 1){
                islandMaxArea++;
                //visited[pos[0]][pos[1]] = true; // mark as visited

                vector<array<int, 2>> neighbours = 
                {{pos[0] + 1, pos[1]}, 
                {pos[0] - 1, pos[1]}, 
                {pos[0], pos[1] + 1}, 
                {pos[0], pos[1] - 1}};


                for(auto& neighbour : neighbours){
                    if(isValid(grid, neighbour[0], neighbour[1])){
                        if(!visited[neighbour[0]][neighbour[1]] && grid[neighbour[0]][neighbour[1]] == 1){
                            q.push({neighbour[0], neighbour[1]});
                            visited[neighbour[0]][neighbour[1]] = true;
                        }
                    } 
                }
            }
        }

        return islandMaxArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    int islandMaxArea = bfs(grid, i, j);

                    if(islandMaxArea > maxArea){
                        maxArea = islandMaxArea;
                    }
                }
            }
        }

        return maxArea;
    }
};
