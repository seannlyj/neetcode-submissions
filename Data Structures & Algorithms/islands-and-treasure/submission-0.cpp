// bfs
// queue<Node*> q;
// q.push(root);
// visited[root] = true;
// while(!q.empty()) {
//      Node* n = q.front();
//      q.pop();
//      
//      process node
//
//      foreach(neighbour in n->neighbours)
//          if(!visited[neighbour])
//              q.push(neighbour);
//              visited[neighbour] = true;
//}

class Solution {
public:
    int INF = 2147483647;

    bool isValid(vector<vector<int>>& grid, int x, int y){
        return x >= 0 && x < grid.size() && y >=0 && y < grid[0].size();
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<array<int,2>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        while(!q.empty()){
            array<int, 2> tPos = q.front();
            q.pop();

            vector<array<int, 2>> neighbours = {
                {tPos[0] + 1, tPos[1]},
                {tPos[0] - 1, tPos[1]},
                {tPos[0], tPos[1] + 1},
                {tPos[0], tPos[1] - 1}
            };

            for(auto& neighbour : neighbours){
                int nX = neighbour[0];
                int nY = neighbour[1];

                if(isValid(grid, nX, nY) && grid[nX][nY] == INF){
                    grid[nX][nY] = grid[tPos[0]][tPos[1]] + 1;
                    q.push({nX, nY});
                }
            }

        }
    }
};
