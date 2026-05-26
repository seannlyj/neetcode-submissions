class Solution {
public:
    // for each string in input
    //      initialize a count array of 26 with all zeroes
    //      for each character c in string, increment count at corresponding order
    //      convert count array into a tuple and use it as a key
    //      append string to list associated with this key

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;

        // for each string in put
        for(auto &s : strs) {
            // for each character c in string, increment count at corresponding order
            vector<int> count(26, 0);
            for(char c : s) {
                count[c - 'a']++;
            }

            // convert count array into tuple and use as key
            string key = to_string(count[0]);
            for(int i = 1; i < 26; ++i){ 
                key += "," + to_string(count[i]);
            }
                
            // append count array into a tuple and use it as a key
            um[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto& element : um)
        {
            result.push_back(element.second);
        }
        return result;
    }
};
