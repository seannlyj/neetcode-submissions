class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            int startingStation = i;
            int currentStation = i;
            int currGas = gas[i];

            while(currGas > 0){
                //reduce currgas to go to next station
                currGas -= cost[currentStation];


                if(currGas < 0) break;

                currentStation++;
                //wrap around
                if(currentStation == gas.size()){ 
                    currentStation = 0;
                }
                
                // check if we did a loop
                if(currentStation == startingStation) {
                    return startingStation;
                }

                //add gas to refill from station
                currGas += gas[currentStation];
            }

            cout<<endl;
        }

        return -1;
    }
};
