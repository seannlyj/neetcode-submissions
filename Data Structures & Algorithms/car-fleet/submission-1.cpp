class Solution {
// Monotonic Stack that contains the cars that are all the way at the front
// if the car's position at the front reaches target, we pop.
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort in descending
        vector<pair<int, int>> cars; //<position, speed>

        for(int i = 0; i < position.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        // monotonic stack
        stack<float> fleetTime;
        float frontCarTime = (float)(target - cars[0].first) / (float)cars[0].second;
        fleetTime.push(frontCarTime);
        cout<<"Adding Time " << frontCarTime<< " to stack"<<endl;

        for(int i = 1; i < cars.size(); i++){
            float topTime = fleetTime.top();
            float timeTaken = (float)(target - cars[i].first) / (float)cars[i].second; 

            if(timeTaken > topTime){
                fleetTime.push(timeTaken);
                cout<<"New fleet is created because the time taken " << timeTaken <<" > topTime "<<topTime<<endl; 
            }
        }

        return fleetTime.size();
    }
};
