class Solution {
// 1-INDEXED

public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        unordered_map<int, vector<int>> trustList; // contains the values of who this element trusts

        // create an adjlist that represents the people that trust this specific element
        vector<vector<int>> adjList(n + 1);
        for(auto t : trust){
            int person = t[0];
            int trusted = t[1];

            adjList[trusted].push_back(person);
            trustList[person].push_back(trusted);
        }

        for(int i = 1; i < adjList.size(); i++){
            if(adjList[i].size() == n - 1 && trustList[i].empty()){
                return i;  
            } 
        }

        return -1;
    }
};