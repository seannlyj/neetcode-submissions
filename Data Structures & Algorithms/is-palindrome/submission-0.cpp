class Solution {
public:
    bool isPalindrome(string s) {
        string str = s;
        // lowercase every char in string
        for(int i = 0; i < s.length(); i++) {
            str[i] = tolower(str[i]);
        }
        // remove non-alphanumerics
        erase_if(str, [](unsigned char c) {
            return !isalnum(c);
        });

        // iterate through from start to middle
        int n = str.length();

        // A B B B A
        // 0 1 2 3 4
        // n = 5
        // n / 2 = 2

        // W A S I T A C A R O R  A  C  A  T  I  S  A  W
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
        // n = 19
        // n / 2 = 9

        for(int i = 0; i < n / 2; ++i)
        {
            if(str[i] != str[n-i-1])
                return false;
        }
        
        return true;
    }
};
