class Solution {

// each row must contain digits 1 - 9 without duplicates ()
// each column must contain digits 1 - 9 without duplicates ()

// hash map? unordered_map<int, unordered_set<char>> currRow
// currRow[row].push_back(rowChar)

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> subboxes;
        unordered_map<int, unordered_set<char>> currCol;
        for(int i = 0; i < board.size(); i++){
            unordered_set<char> currRow;

            for(int j = 0; j < board[i].size(); j++){
                char currCh = board[i][j];
                if(currCh == '.') continue;

                if(currRow.count(currCh)) return false;
                else currRow.insert(currCh);

                if(currCol[j].count(currCh)) return false;
                else currCol[j].insert(currCh);

                int subboxRow = i / 3;
                int subboxCol = j / 3;
                int currSubbox = (subboxRow * (board[i].size() / 3)) + subboxCol;

                if(subboxes[currSubbox].count(currCh)) return false;
                else subboxes[currSubbox].insert(currCh);

            }

            currRow.clear();
        }

        return true;
    }
};
