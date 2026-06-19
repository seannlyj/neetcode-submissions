class Solution {
public:
    int hoursTakenToEat(vector<int> piles, int eatingRate){
        int h = 0;
        int pileIndex = 0;

        for(int i = 0; i < piles.size(); i++){
            h += ceil((double)piles[i]/(double)eatingRate);
        }

        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int minEatingSpeed = r;

        while(l <= r){
            int m = l + (r-l) / 2;
            int timeTaken = hoursTakenToEat(piles, m);
            
            if(timeTaken <= h){
                minEatingSpeed = min(minEatingSpeed, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return minEatingSpeed;
    }
};
