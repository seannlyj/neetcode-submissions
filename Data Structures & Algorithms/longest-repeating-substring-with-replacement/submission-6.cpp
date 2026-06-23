class Solution {
// dynamic sliding window
// When do we shrink left? we shrink when we cannot hold any more different characters given k
// We shrink until
// When do we expand right? Always
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int length = 0;
        int maxfreq = 0;

        int freq[26] = {};

        for(int r = 0; r < s.size(); r++){
            freq[s[r] - 'A']++;
            maxfreq = max(maxfreq, freq[s[r] - 'A']);

            while((r - l + 1) - maxfreq > k){
                freq[s[l] - 'A']--;
                l++;
            }

            length = max(length, r - l + 1);
        }

        return length;
    }
};
