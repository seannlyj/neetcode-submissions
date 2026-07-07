class Solution {
// choice: which alphabet to map to given the current digit we're on
// complete: length of combi == length of digits
// prune: 

public:
    void recursion(string digits, vector<string>& result, string combi, int index, unordered_map<int, vector<char>> &hm){
        //base case
        if(combi.length() == digits.length()){
            result.push_back(combi);
            return;
        }

        int digit = digits[index] - '0';
        cout<<digit<<endl;
        // iterate through all characters for this digit
        for(auto c : hm[digit]){
            //push
            combi.push_back(c);
            //recurse
            recursion(digits, result, combi, index + 1, hm);
            //pop
            combi.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        // hash table to map digit : characters
        unordered_map<int, vector<char>> hm;
        char starting = 'a';
        for(int i = 2; i <= 9; i++){
            if(i == 9 || i == 7){
                for(int j = 0; j < 4; j++){
                    hm[i].push_back(starting);
                    starting++;
                }
            } else {
                for(int j = 0; j < 3; j++){
                    hm[i].push_back(starting);
                    starting++;
                }
            }
        }

        if(digits.empty()) return {};
        
        string combi;
        vector<string> result;
        recursion(digits, result, combi, 0, hm);
        return result;
    }
};
