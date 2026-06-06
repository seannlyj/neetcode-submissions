class Solution {
// What is a well formed parenthesis?
// (): opening ( will always have a closing )

//choice: put ( or )
//prune when: NIL because of checks made when deciding to put ( or )
//completed when: no. of parenthesises made == 2n
public:
    void backtracking(int n, int open, int close, string& curr, vector<string>& result){
        // complete
        if(open+close == 2*n){
            result.push_back(curr);
        }

        //choice: choosing ( or ) to put in string
        if(open < n){
            curr.push_back('(');
            backtracking(n, open + 1, close, curr, result);
            curr.pop_back();
        }

        if(close < open){
            curr.push_back(')');
            backtracking(n, open, close + 1, curr, result);
            curr.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backtracking(n, 0, 0, curr, result);
        return result;
    }
};
