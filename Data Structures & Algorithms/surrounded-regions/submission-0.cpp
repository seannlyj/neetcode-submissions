/*

00, 01, 02, 03
10, 11, 12, 13
20, 21, 22, 23
30, 31, 32, 33

*/

class Solution {
public:

    void dfs(vector<vector<char>>& board, int startingX, int startingY){
        //mark startingX and startingY as visited
        board[startingX][startingY] = 'V';

        vector<pair<int, int>> neighbours = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
        stack<pair<int, int>> s;
        s.push({startingX, startingY});

        while(!s.empty()){
            pair<int, int> n = s.top();
            s.pop();

            // check neigbours for 'O'
            for(auto neighbour : neighbours){
                int x = n.first + neighbour.first;
                int y = n.second + neighbour.second;

                if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()){
                    if(board[x][y] == 'O'){
                        board[x][y] = 'V';
                        s.push({x, y});
                    }
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                //go through all borders
                if((i == 0) || (j == 0) || (i == board.size() - 1) || (j == board[i].size() - 1)){
                    if(board[i][j] == 'O'){
                        dfs(board, i, j);
                    }
                }
        
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'V')
                    board[i][j] = 'O';
            }
        }
    }
};
