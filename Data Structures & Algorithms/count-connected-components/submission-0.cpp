class Solution {
public:
    void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int start){
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while(!s.empty()){
            int node = s.top();
            s.pop();

            // dfs into neighbours
            for(auto neighbour : adjList[node]){
                if(!visited[neighbour]) {
                    visited[neighbour] = true;
                    s.push(neighbour);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // Build an adjacency list
        // 0 : [1]
        // 1 : [0, 2]
        // 2 : [1]
        // 3 : [4]
        // 4 : [3]
        vector<vector<int>> adjList(n);
        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // How do we detect disconnected graphs?
        // if we dfs and not all nodes come up as visited
        int result = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]) {
                dfs(adjList, visited, i);
                result++;
            }
        }
        return result;
    }
};
