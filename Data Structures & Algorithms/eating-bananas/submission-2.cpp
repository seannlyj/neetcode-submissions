class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res;

        while(l <= r){
            int m = l + (r - l) / 2;

            if(!finishBananasInHHours(h, m, piles)){
                // if cannot finish bananas in current hours, need more time
                l = m + 1;
                
            } else {
                // can finish bananas in current hours, try smaller period
                res = m;
                r = m - 1;
            }
        }

        return res;
    }

    // returns true if given k eating speed, it can finish in h hours
    bool finishBananasInHHours(int h, int k, vector<int> piles){
        // h = max hours
        // k = eating speed
        int totalTime = 0;

        for(int p : piles){
            totalTime += ceil(static_cast<double>(p) / k);
        }

        if(totalTime <= h) {
            return true;
        } else {
            return false;
        }

    }
};
