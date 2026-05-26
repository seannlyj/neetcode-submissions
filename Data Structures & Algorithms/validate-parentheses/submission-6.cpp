class Solution {
public:
    // [ ( ) ]
    // Stack Top: (
    // Stack Btm: [

    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if(ch == '(' ||  ch == '[' || ch == '{')
            {
                if(i == s.length() - 1)
                    return false;

                st.push(ch);
            }

            if(st.empty())
                return false;

            if(ch == ')')
            {
                char stackTopChar = st.top();

                if(stackTopChar == '(')
                    st.pop();
                else
                    return false;
            }
            else if(ch == ']')
            {
                char stackTopChar = st.top();

                if(stackTopChar == '[')
                    st.pop();
                else
                    return false;
            }
            else if (ch == '}')
            {
                char stackTopChar = st.top();

                if(stackTopChar == '{')
                    st.pop();
                else
                    return false;
            }
        }

        if(st.empty())
            return true;

        return false;
    }
};
