class Solution {
// static sliding window
// build first window (calculate difference between x and arr[i] and sum all up)
// iterate through
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int bestSum = 0;
        int sum = 0;
        set<int> nodes;
        vector<int> result;

        int l = 0;
        // build first window
        for(int i = 0; i < k; i++){
            sum += abs(x - arr[i]);
            nodes.insert(arr[i]);
            result.push_back(arr[i]);
        }
        bestSum = sum;

        for(int i = k; i < arr.size(); i++){
            sum -= abs(x - arr[l]); // remove front element
            sum += abs(x - arr[i]); // add new element
            if(sum < bestSum){
                bestSum = sum;
                nodes.erase(arr[l]);
                nodes.insert(arr[i]);
                result.erase(result.begin());
                result.push_back(arr[i]);
            }
            l++;
        }

        sort(result.begin(), result.end());
        // for(auto node : nodes){
        //     result.push_back(node);
        // }

        return result;
    }
};