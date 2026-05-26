class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;

        unordered_set<char> charSet;

        for(int r = 0; r < s.length(); ++r) {
            // Character is currently already inside charSet (VIOLATES CONDITION for longest subarray)
            while(charSet.find(s[r]) != charSet.end()){
                charSet.erase(s[l]);    //remove the thing that is causing the violation
                l++;
            }
            // Add arr[right] to window state
            charSet.insert(s[r]);
            // Update result based on current window
            res = max(res, r - l + 1);

        }

        return res;
    }
};
