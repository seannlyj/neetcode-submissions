class Solution {
    //choice: try all 4 neighbors
    //prune when: neighbor is not available (out of bounds, doesnt have right character, already on current string)
    //complete when: the total word matches

    // will need a vector<vector<bool>> visited to keep track of cells that we have already visited
public:
    bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int x, int y, int currCharIndex){        
        // pruning
        // out of bounds
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        // visited already
        if(visited[x][y]) return false;
        // doesn't have the right character
        if(board[x][y] != word[currCharIndex]) return false;
        else {
            currCharIndex++;
        }

        // complete solution found
        if(currCharIndex == word.length()) return true;

        visited[x][y] = true;
        vector<pair<int, int>> neighbors = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto neighbor : neighbors) {
            if(backtrack(board, word, visited, x + neighbor.first, y + neighbor.second, currCharIndex))
                return true;
        }
        visited[x][y] = false;   
        return false;     
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                bool result = backtrack(board, word, visited, i, j, 0);
                if(result) return true;
            }
        }

        return false;
    }
};
