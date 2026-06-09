class Solution {
public:

        // [1,2,3,3,4,5,6,7]
        // 1 : 1
        // 2 : 1
        // 3 : 2
        // 4 : 1
        // 5 : 1
        // 6 : 1
        // 7 : 1

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;

        if(hand.size() % groupSize != 0) return false;

        for(int card : hand){
            m[card]++;
        }

        // iterate through cards
        for(auto &[key,val] : m) {
            if(val > 0) {
                int count = val;
                //start consecutive consumption of cards
                for(int i = 0; i < groupSize; i++){
                    m[key + i] -= count;
                    if(m[key + i] < 0) return false;
                }
            }
        }

        return true;
    }
};
