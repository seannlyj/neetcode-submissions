class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int bot = rows - 1;
        int selectedRow = -999;

        while(top <= bot){
            int mid = top + (bot - top)/ 2;

            if(matrix[mid][0] > target){
                // target is above the mid row
                bot = mid - 1;
            } else if(matrix[mid][cols - 1] < target){
                // target is below the mid row
                top = mid + 1;
            } else {
                //target is within this row, find it
                selectedRow = mid;
                break;
            }
        }

        if(selectedRow == -999){
            return false;
        } else {
            cout<<"Selected Row: " << selectedRow <<endl;
        }

        int l = 0;
        int r = cols - 1;

        while(l <= r){
            int m = l + (r - l) / 2;
            if(matrix[selectedRow][m] == target) {
                return true;
            } else if (matrix[selectedRow][m] > target) {
                //value is bigger than target, it should be on the left
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return false;
    }
};
