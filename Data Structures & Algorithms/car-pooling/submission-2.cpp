class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // minheap stores <from, to, numPassengers>
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minheap;
        for(auto trip : trips){
            minheap.push({trip[1], trip[2], trip[0]});
        }

        vector<tuple<int, int, int>> onCar;
        while(!minheap.empty()){
            auto [from, to, numPassengers] = minheap.top();
            minheap.pop();

            // remove any boarded passengers if they arrived at their locations
            vector<int> toRemove;
            for(int i = 0; i < onCar.size(); i++){
                auto [onCarFrom, onCarTo, onCarPassengers] = onCar[i];

                if(onCarTo <= from){
                    capacity += onCarPassengers;
                    toRemove.push_back(i);
                }
            }
            for(int i = toRemove.size() - 1; i >= 0; i--){
                auto [onCarFrom, onCarTo, onCarPassengers] = onCar[i];
                onCar.erase(onCar.begin() + toRemove[i]);
            }
            
            if(capacity - numPassengers < 0 ) return false;
            capacity -= numPassengers;
            onCar.push_back({from, to, numPassengers});
        }

        return true;
    }
};