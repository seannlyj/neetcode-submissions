class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while(l <= r){
            if(!isalnum(s[l])) { 
                l++;
                continue;
            }

            if(!isalnum(s[r])) {
                r--;
                continue;
            }

            cout<<"Comparing s[l] = "<<s[l] <<" and s[r] = "<<s[r]<<endl;
            if(tolower(s[l]) != tolower(s[r])){
                cout<<"returned false when s[l] = " << s[l] << " and s[r] = "<<s[r]<<endl;
                return false;
            } else {
                l++;
                r--;
            }
        }

        return true;
    }
};
