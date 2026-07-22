class Solution {
public:
    int characterReplacement(string s, int k) {
        // dynamic sliding window
        // compacts left side when: actively increase/decrease the frequency of the characters?
        // how to keep track: build an int freq[26];

        int result = 0;
        int maxfreq = 0;
        int freq[26] = {};
        int l = 0;
        int counter = 0;

        for(int r = 0; r < s.size(); r++){
            freq[s[r] - 'A']++;

            // get the biggest possible frequency 
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            // if the current length of the sliding window > biggest freqency
            while((r-l+1) - k > maxfreq){
                freq[s[l] - 'A']--;
                l++;
            }

            result = max(0, r-l+1);
        }

        return result;
    }
};
