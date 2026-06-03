class Solution {
public:
    int characterReplacement(string s, int k) {
                //dynamic
        //what is the constraint?
        //shrink window when = windowSize - max count of character > k
        int left = 0;
        int longest = 0;
        int freq[26] = {};
        int maxf = 0;

        for(int right = 0; right < s.size(); right++){
            freq[s[right] - 'A']++;
            maxf = max(maxf, freq[s[right] - 'A']);

            while((right - left + 1) - maxf > k){
                freq[s[left] - 'A']--;
                left++;
            }

            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
