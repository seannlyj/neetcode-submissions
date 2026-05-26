class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;

        for(int i = 0; i < nums.size(); i++)
        {
            int key = nums[i];

            // check if umap already has key
            if(um.contains(key)) {
                // if key exists, increment value
                int value = um[key];
                value += 1;
                um.at(key) = value;
            }
            // if no key exists, create one
            else {
                um.insert({key, 1});
            }
        }

        int counter = k;
        vector<int> topNumber;

        while(counter > 0)
        {
            int bestValue = 0;
            int bestKey = 0;
            // iterate through umap to get most frequent
            for(auto it = um.begin(); it != um.end(); it++)
            {
                if(it->second > bestValue)
                {
                    bestValue = it->second;
                    bestKey = it->first;
                }
            }

            topNumber.push_back(bestKey);
            um.erase(bestKey);
            counter--;
        }

        return topNumber;
    }
};
