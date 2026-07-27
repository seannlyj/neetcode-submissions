class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> charHM;
        string human = "abcdefghijklmnopqrstuvwxyz";
    
        for(int i = 0; i < 26; i++){
            charHM[order[i]] = human[i];
        }

        vector<string> humanwords;
        for(auto word : words){
            string humanword = word;
            for(int i = 0; i < word.length(); i++){
                humanword[i] = charHM[word[i]];
            }
            cout<<word<<" in human: " << humanword <<endl;
            humanwords.push_back(humanword);
        }

        vector<string> humanwordsRef = humanwords;

        sort(humanwords.begin(), humanwords.end());

        for(int i = 0; i < humanwordsRef.size(); i++){
            if(humanwordsRef[i] != humanwords[i])
                return false;
        }

        return true;
    }
};