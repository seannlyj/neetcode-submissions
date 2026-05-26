class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        char s1freq[26] = {};
        char s2freq[26] = {};
        int fixedWindowSize = s1.length();

        for(int i = 0; i < s1.length(); ++i) {
            int charIndex = s1[i] - 'a';
            s1freq[charIndex]++;
        }

        if(s1.length() > s2.length()) return false;

        // sliding window
        // build first window
        for(int i = 0; i < fixedWindowSize; i++){
            s2freq[s2[i] - 'a']++;
        }

        // check if value is valid
        if(check(s1freq, s2freq)){
            return true;
        }

        // slide through array
        for (int i = fixedWindowSize; i < s2.length(); i++) {
            // add new char from s2
            s2freq[s2[i] - 'a']++;

            // remove old char from front of s2
            s2freq[s2[i - fixedWindowSize] - 'a']--;

            if(check(s1freq, s2freq)){
                return true;
            }
        }

        return false;
    }

    bool check(char s1freq[], char s2freq[]){
        // check between s1 freq and s2 freq if they are the same
        for(int i = 0; i < 26; i++){
            if(s1freq[i] != s2freq[i])
                return false;
        }

        return true;
    }
};
