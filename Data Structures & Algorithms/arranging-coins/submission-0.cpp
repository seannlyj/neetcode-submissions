class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0;
        int steps = 1;
        while(n > 0){
            if(n - steps >= 0){
                row++;
            }
            n -= steps;
            steps++;
        }

        return row;
    }
};