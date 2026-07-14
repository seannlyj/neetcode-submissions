class Solution {
public:
    string simplifyPath(string path) {
        // slashes = signifies start of next file's directory
        // double period = pop
        // single period = ignore
        // anything else = push

        vector<string> s;

        int i = 0;
        while(i < path.size()){
            //skip brackets
            while(i < path.size() && path[i] == '/') i++;
            int tokenStart = i;
            while(i < path.size() && path[i] != '/') i++;
            int tokenLength = i - tokenStart;
            string token = path.substr(tokenStart, tokenLength);

            if(token == "..") {
                if(!s.empty()) s.pop_back();
            } else if(token != "." && token.length() > 0) {
                s.push_back(token);
            }
        }

        // construct string
        string result = "/";

        for(int j = 0; j < s.size(); j++){
            result+=s[j];

            if(j + 1 < s.size()){
                result += "/";
            }
        }

        return result;
    }
};