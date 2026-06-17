class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> nodupnumsSet;

        for(auto num : nums){
            nodupnumsSet.insert(num);
        }

        vector<int> nodupnums;
        for(auto num : nodupnumsSet){
            nodupnums.push_back(num);
            cout<< num <<", ";
        }

        cout<<endl;

        // <startingIndex, no. of consecutive elements>
        unordered_map<int, int> hm;

        for(int i = 0; i < nodupnums.size(); i++){
            int consecutives = 1;
            for(int j = i; j < nodupnums.size() - 1; j++){
                if(nodupnums[j] + 1 == nodupnums[j + 1]){
                    consecutives++;
                } else {
                    break;
                }
            }
            cout<<"For index " << i <<", there are " << consecutives <<" consecutive elements"<<endl;
            hm.insert({i, consecutives});
        }

        if(hm.empty()) return 0;

        int maxVal = -INT_MAX;
        for(auto &[key, val] : hm){
            maxVal = max(maxVal, val);
        }

        return maxVal;
    }
};
