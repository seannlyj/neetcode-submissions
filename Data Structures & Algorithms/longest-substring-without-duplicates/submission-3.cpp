class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        int length = 0;
        unordered_set<char> charset;

        for(int right = 0; right < s.length(); right++){
            while(charset.count(s[right])){
                charset.erase(s[left]);
                length--;
                left++;
            }

            length++;
            charset.insert(s[right]);
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
