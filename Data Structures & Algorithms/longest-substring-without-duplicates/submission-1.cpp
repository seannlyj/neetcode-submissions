class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int left = 0;
        unordered_set<char> c;

        for(int right = 0; right < s.length(); right++){
            while(c.find(s[right]) != c.end()){
                c.erase(s[left]);
                left++;
            }

            c.insert(s[right]); 
            result = max(result, right - left + 1);
        }

        return result;
    }
};
