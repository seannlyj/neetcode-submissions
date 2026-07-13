class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(auto op : operations){
            if(op == "C") {
                s.pop();
            } else if (op == "D") {
                s.push(s.top() * 2);
            } else if (op == "+") {
                int a = s.top(); s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);
            } else {
                int num = stoi(op);
                s.push(num);
            }
        }

        int result = 0;
        while(!s.empty()){
            result += s.top();
            s.pop();
        }
        return result;
    }
};