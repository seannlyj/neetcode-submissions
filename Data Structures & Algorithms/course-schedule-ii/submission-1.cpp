class Solution {
    // 0 INDEXED
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, vector<int>& result){
        visited[node] = true;
        recStack[node] = true;

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor, adj, visited, recStack, result)) return true;
            } else if(recStack[neighbor]){
                return true;
            }
        }

        recStack[node] = false;
        result.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites){
            int a = p[0];
            int b = p[1];

            adj[a].push_back(b);
        }

        /* Example adj list
        [0, 1] [1, 2] [2, 0]
        adj[0] : 1
        adj[1] : 2
        adj[2] : 0
        */

        //Cyclic Detection
        vector<int> result = {};
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && dfs(i, adj, visited, recStack, result)){
                // cycle detected
                return {};
            }
        }

        return result;
    }
};
