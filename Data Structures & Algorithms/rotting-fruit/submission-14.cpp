class Solution {
public:
    bool isValid(int xBound, int yBound, int x, int y){
        return x >= 0 && x < xBound && y >= 0 && y < yBound;
    }

    void bfs(vector<vector<int>>& grid, vector<pair<int,int>> rottingOrangesStart, vector<pair<int, int>> neighbours, int& minutes){
        queue<pair<int, int>> q;

        for(int i = 0; i < rottingOrangesStart.size(); i++){
            q.push(rottingOrangesStart[i]);
        }
        
        while(!q.empty()){
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                pair<int,int> node = q.front();
                q.pop();

                for(auto [nX, nY] : neighbours){
                    int checkX = nX + node.first;
                    int checkY = nY + node.second;
                    if(isValid(grid.size(), grid[0].size(), checkX, checkY)){
                        if(grid[checkX][checkY] == 1) { 
                            q.push({checkX, checkY});
                            grid[checkX][checkY] = 2;
                            cout<<"Neighbour["<<checkX<<"]["<<checkY<<"] is 1"<<endl;
                        }
                    }
                }
            }

            if(!q.empty())
                minutes++;
            
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> neighbours = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int minutes = 0;

        vector<pair<int, int>> rottingOranges;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 2){
                    rottingOranges.push_back({i,j});
                }
            }
        }

        //multi source bfs by pushign everything into queue immediately before starting
        bfs(grid, rottingOranges, neighbours, minutes);

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return minutes;
    }
};
