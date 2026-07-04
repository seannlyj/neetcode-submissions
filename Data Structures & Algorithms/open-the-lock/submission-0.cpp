class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend_set;
        for(auto deadend : deadends){
            deadend_set.insert(deadend);
        }

        unordered_set<string> visited;

        //we dont bfs into neighbours that are in deadends
        if(deadend_set.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int numberOfTurns = 0;

        while(!q.empty()){
            int levelSize = q.size();

            for(int j = 0; j < levelSize; j++){
                string combi = q.front(); q.pop();
                if(combi == target) return numberOfTurns;

                for(int i = 0; i < 4; i++){
                    int digit = combi[i] - '0';
                    //generate a string for after going up AND going down with this specific digit
                    int up = (digit + 1) % 10;
                    int down = (digit - 1 + 10) % 10;

                    string sUp = combi;
                    sUp[i] = up + '0';
                    if(!deadend_set.count(sUp) && !visited.count(sUp)) {
                        visited.insert(sUp);
                        q.push(sUp);
                    }

                    string sDown = combi;
                    sDown[i] = down + '0';
                    if(!deadend_set.count(sDown) && !visited.count(sDown)) {
                        visited.insert(sDown);
                        q.push(sDown);
                    }

                }
            }
            numberOfTurns++;

        }

        return -1;
    }
};