class Solution {
public:
    // given weight capacity and weights of each package, returns no. of days needed
    int daysNeeded(vector<int>& weights, int weightCapacity){
        int days = 1;
        int currentWeight = 0;

        for(int r = 0; r < weights.size(); r++){
            currentWeight += weights[r];

            if(currentWeight > weightCapacity){
                days++;
                currentWeight = weights[r];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // binary search the weight capacity (after getting max weight?)
        int maxWeight = 0;
        int totalWeight = 0;
        for(auto weight : weights){
            maxWeight = max(maxWeight, weight);
            totalWeight += weight;
        }

        int l = maxWeight;
        int r = totalWeight;
        int result = totalWeight;
        while(l <= r){
            int m = l + (r-l)/2;
            int totalDays = daysNeeded(weights, m);

            // if total days needed is more, weight capacity needs to increase
            if(totalDays > days){
                l = m + 1;
            } else if(totalDays <= days){
                r = m - 1;
                result = min(result, m);
            }
        }

        return result;

    }
};