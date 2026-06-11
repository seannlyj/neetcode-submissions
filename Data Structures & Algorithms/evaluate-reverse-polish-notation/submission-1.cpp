class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for(auto& token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                //Pop two numbers and apply the operator
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();

                int operation = 0;
                if(token == "+") operation = num1 + num2;
                else if(token == "-") operation = num1 - num2;
                else if(token=="*") operation = num1 * num2;
                else operation = num1 / num2;

                numbers.push(operation);

            } else {
                numbers.push(stoi(token));
            }
        }

        return numbers.top();
    }
};
