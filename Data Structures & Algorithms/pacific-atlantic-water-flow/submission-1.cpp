class Solution {
public:
    bool isValid(int rowSize, int colSize, int x, int y){
        return x >= 0 && x < rowSize && y >= 0 && y < colSize;
    }

    bool canFlow(vector<vector<int>>& heights, vector<pair<int, int>>& neighbours, vector<vector<bool>>& visited, int x, int y){
        //Use bfs
        queue<pair<int, int>> q;
        q.push({x, y});

        bool reachedPacific = false;
        bool reachedAtlantic = false;

        while(!q.empty()){
            pair<int, int> node = q.front();
            q.pop();

            // check if this node has reached Pacific or Atlantic
            int nodeX = node.first;
            int nodeY = node.second;           

            visited[nodeX][nodeY] = true;

            // Check if it touches Pacific
            if(nodeY == 0 || nodeX == 0) reachedPacific = true;
            // Check if it touches Atlantic
            if(nodeX + 1 == heights.size() || nodeY + 1== heights[0].size()) reachedAtlantic = true;

            if(reachedPacific && reachedAtlantic) return true;
            

            for(auto neighbour: neighbours){
                int newX = node.first + neighbour.first;
                int newY = node.second + neighbour.second;
                if(isValid(heights.size(), heights[0].size(), newX, newY)){ 
                    // if water can flow to this area
                    if(heights[newX][newY] <= heights[node.first][node.second] && !visited[newX][newY]){
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }

                }
            }
        }

        return false;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<pair<int, int>> neighbours = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> result = {};

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[i].size(); j++){
                vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
                if(canFlow(heights, neighbours, visited, i, j)) result.push_back({i, j});
            }
        }

        return result;
    }
};
