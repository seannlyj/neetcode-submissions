class Solution {
// choice: try every possible endpoint from start to end of string
// prune when: not a palindrome
// completed when: start == s.length(), covered every character

// palindrome detection: two pointers
// providing a string, a start, and a end
// if string[start] == string[end], continue
// while start < end;

public:
    bool palindrome(const string &s, int l, int r) {
        while(l < r){
            if(s[l] != s[r]) return false;

            l++;
            r--;
        }
        return true;
    }

    void backtracking(const string &s, int start, vector<string>& curr, vector<vector<string>>& result) {
        // it is completed
        if(start == s.length()){
            result.push_back(curr);
            return;
        }

        for(int end = start; end < s.length(); end++){
            if(palindrome(s, start, end)){
                curr.push_back(s.substr(start, end - start + 1));
                backtracking(s, end + 1, curr, result);
                curr.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        backtracking(s, 0, curr, result);

        return result;
    }
};
