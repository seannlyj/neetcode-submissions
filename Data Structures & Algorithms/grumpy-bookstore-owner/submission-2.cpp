class Solution {
// 1 = grumpy
// 0 = not grumpy

//fixed sliding window with size = minutes
//get biggest no. of customers 
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;

        //build first window
        for(int i = 0; i < minutes; i++){
            if(grumpy[i] == 1) satisfied += customers[i];
        }

        int maxSatisfied = satisfied;
        int maxStart = 0;

        //cout<<"Window: 0" << " to "<<minutes - 1<<endl;
        //cout<<satisfied<<endl;

        //move window
        for(int i = minutes; i < customers.size(); i++){

            if(grumpy[i - minutes] == 1){
                satisfied -= customers[i - minutes];
            }

            if(grumpy[i] == 1) {
                satisfied += customers[i];
            }
            cout<<customers[i] <<" at index "<< i <<endl;
            //cout<<"Window: "<< i - minutes + 1 << " to "<<i<<endl;
            cout<<satisfied<<endl;

            if(satisfied > maxSatisfied){
                maxSatisfied = satisfied;
                maxStart = i - minutes + 1;
            }
        }

        //cout<<"Use secret technique at " << maxStart<<"th minute"<<endl;

        int sum = 0;
        for(int i = 0; i < customers.size(); i++){
            if(grumpy[i] == 1 && i >= maxStart && i < maxStart + minutes){
                //cout<<"Adding "<<customers[i] <<endl;
                sum += customers[i];
                //continue;
            }

            if(grumpy[i] == 0){
                //cout<<"Adding " << customers[i]<<endl;
                sum+= customers[i];
            } 

        }

        return sum;
    }
};