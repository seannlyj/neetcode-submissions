class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            cout<<"Starting Station = " << i << endl;
            int startingStation = i;
            int currentStation = i;
            int currGas = gas[i];
            cout<<"currGas = "<<currGas<<endl;

            while(currGas > 0){
                //reduce currgas to go to next station
                currGas -= cost[currentStation];

                cout<<"CurrGas after leaving Station "<<currentStation<<" = "<<currGas<<endl;

                if(currGas < 0) break;

                currentStation++;
                //wrap around
                if(currentStation == gas.size()){ 
                    cout<<"Current station we're at is at the end, we'll wrap around"<<endl; 
                    currentStation = 0;
                }
                
                // check if we did a loop
                if(currentStation == startingStation) {
                    cout<<"A  full loop is done, returning" << endl; 
                    return startingStation;
                }

                //add gas to refill from station
                currGas += gas[currentStation];
                cout<<"CurrGas refilled at Station "<<currentStation<<" = " << currGas<<endl;

            }

            cout<<endl;
        }

        return -1;
    }
};
