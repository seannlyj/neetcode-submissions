class Solution {
public:
    bool dfs(vector<vector<int>> & adjList, vector<bool>& visited, vector<int>& parent, int start){
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while(!s.empty()) {
            int node = s.top();
            s.pop();

            for(auto neighbour : adjList[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    parent[neighbour] = node;
                    s.push(neighbour);
                }
                else if (visited[neighbour] && parent[node] != neighbour){
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //Build an adjacency list
        /*
        1 : [2, 3]
        2 : [1, 4]
        3 : [1, 4]
        4 : [2, 3]
        */
        // convert a cyclic graph into non-cyclical
        // detect the moment it becomes cyclic: when we try to visit the same node twice
        // dfs and store visited and parent, if neighbour is visited and not the parent of current node (cycle detected)
        int n = edges.size() + 1;
        vector<vector<int>> adjList(n);

        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            vector<bool> visited(n, false);
            vector<int> parent(n, -1);

            if(dfs(adjList, visited, parent, edge[0])) {
                return {edge[0], edge[1]};
            }
        }

        return {};
    }
};
