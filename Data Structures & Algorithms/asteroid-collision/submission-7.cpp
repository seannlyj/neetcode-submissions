class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int& a : asteroids){
            bool p = true;
            while(!s.empty() && a < 0 && s.top() > 0){
                int ast1 = s.top();
                int ast2 = abs(a);
                if(ast2 > ast1){
                    s.pop();
                } else if (ast2 < ast1){
                    p = false;
                    break;
                } else {
                    s.pop();
                    p = false;
                    break;
                }
            }

            if(a != 0 && p) s.push(a);
        }

        vector<int> result;

        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};