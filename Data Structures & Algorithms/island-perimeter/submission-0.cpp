class Solution {
public:
    bool isValid(vector<vector<int>> &grid, int x, int y){
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size();
    }

    int dfs(vector<vector<int>>&grid, vector<pair<int, int>> &neighbours, int startingX, int startingY){
        int perimeter = 0;
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        stack<pair<int, int>> s;
        s.push({startingX, startingY});
        visited[startingX][startingY] = true;

        while(!s.empty()){
            auto [x, y] = s.top();
            s.pop();
            cout<<x<<", "<<y<<endl;
            int connectedNeighbours = 0;
            for(auto [nX, nY] : neighbours){
                int neighbourX = x + nX;
                int neighbourY = y + nY;

                if(isValid(grid, neighbourX, neighbourY) ) {
                    visited[neighbourX][neighbourY] = true;
                    
                    if(grid[neighbourX][neighbourY] == 1) {
                        cout<<"Neighbour "<< neighbourX <<", "<<neighbourY <<" is a connectedNeighbour"<<endl;
                        connectedNeighbours++;
                        
                        if(!visited[neighbourX][neighbourY])
                            s.push({neighbourX, neighbourY});
                    }
                }
            }
            cout<<"perimeter is " << 4 - connectedNeighbours<<endl;
            perimeter += 4 - connectedNeighbours;
        }

        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        //DFS into every neighbor that is land
        //everytime we dfs, we check how many neighbours are connected
        //we take 4 - no. of neighbours, this will be how many sides are part of the perimeter for that tile

        vector<pair<int, int>> neighbours = {{1,0}, {0,1}, {-1,0}, {0, -1}};
        int perimeter = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 1){
                    perimeter += dfs(grid, neighbours, i, j);
                }
            }
        }

        return perimeter;
    }
};