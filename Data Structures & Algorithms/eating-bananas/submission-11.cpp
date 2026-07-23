class Solution {
public:
    int hoursTaken(vector<int> piles, int eatSpeed){
        int h = 0;
        
        for(int i = 0; i < piles.size(); i++){
            h += ceil((double)piles[i] / eatSpeed);
        }
        cout<<"Given "<<eatSpeed<<", hours taken = "<<h<<endl;
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // what is the minimum eating rate that allows us to finish eating
        // all piles before we reach h?

        // we binary search the eating size
        sort(piles.begin(), piles.end());
        int left = 0;
        int right = piles[piles.size() - 1];

        int eatingSpeed = right;

        while(left <= right){
            int mid = left + (right - left)/2;
            cout<<mid<<endl;
            if(mid == 0) break;

            int hours = hoursTaken(piles, mid);

            // if need more time
            if(hours > h){
                left = mid + 1;
            } 
            // if can have less time
            else {
                right = mid - 1;
                eatingSpeed = min(mid, eatingSpeed);
            }
        }

        return eatingSpeed;
    }
};
