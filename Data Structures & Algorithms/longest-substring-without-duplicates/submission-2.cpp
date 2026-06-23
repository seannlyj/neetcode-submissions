class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        
        int result = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            while(charset.count(s[right])) {
                charset.erase(s[left]);
                left++;
                //result--;
            }
            charset.insert(s[right]);
            //result++;
            result = max(result, right - left + 1);
        }

        return result;
    }
};
