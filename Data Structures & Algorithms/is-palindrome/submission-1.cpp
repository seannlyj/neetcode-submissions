class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while(l < r) {
            char left = tolower(s[l]);
            char right = tolower(s[r]);            
            
            if(!isalnum(left)){
                l++;
                continue;
            }

            if(!isalnum(right)){
                r--;
                continue;
            }

            if(left != right)
                return false;
            
            l++;
            r--;
        }

        return true;
    }
};
