class Solution {
// 0 1 2 3 4 5 6 7 8 9 (l = 0, r = 9, m = 4)
// m = 4, m*m = 16 -> r = 4 - 1 = 3
// m = 1, m*m = 1 -> l = 2;
// m = 2, m*m = 4 -> l = 3;
// m = 3, m*m = 9, done.

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// m = 6, m*m = 32 -> r = 6;
// m = 3, m * m = 9 -> l = 4;
// m = 4, m*m = 16 -> r = 3;
// return l = 4;

public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;

        while(l <= r){
            int m = l + (r - l) / 2;

            if(m == 0)
                break;

            if(m == x/m){
                return m;
            } else if (m > x/m){
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return r;
    }
};