class Solution {
public:
    bool isValidTile(vector<vector<char>>& grid, int row, int col){
        if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size())
            return true;
        
        return false;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if(!isValidTile(grid, row, col)) return;

        stack<array<int, 2>> s;
        s.push({row, col});

        while(!s.empty()) {
            array<int, 2> coord = s.top();
            vector<array<int, 2>> neighbours = { {coord[0] - 1, coord[1]}, {coord[0] + 1, coord[1]}, {coord[0], coord[1] + 1}, {coord[0], coord[1] - 1} };
            s.pop();

            if(grid[coord[0]][coord[1]] == '1'){
                grid[coord[0]][coord[1]] = '0';

                for(auto& neighbour: neighbours){
                    int x = neighbour[0];
                    int y = neighbour[1];

                    if(isValidTile(grid, x, y)) s.push({x, y});
                }
            }
        }   

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    // perform DFS here (it should only explore the island it is triggered on)
                    dfs(grid, i, j);
                    res++;    
                }
            }
        }

        return res;
    }
};
