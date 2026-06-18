class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> mono; // <temperature[i], i>
       
        for(int i = 0; i < temperatures.size(); i++) {

            while(!mono.empty() &&  mono.top().first < temperatures[i]){
                int distance = i - mono.top().second;
                result[mono.top().second] = distance;
                mono.pop();
            }
            mono.push({temperatures[i], i});
        }

        return result;
    }
};
