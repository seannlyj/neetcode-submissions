class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<vector<int>> adjList){
        visited[node] = 1;

        for(int neighbour : adjList[node]){
            if(visited[neighbour] == 1) return false;

            if(visited[neighbour] == 0) {
                if(!dfs(neighbour, visited, adjList)) return false;
            }
        }

        visited[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create an adjacency list
        vector<vector<int>> adj(numCourses);
        for(auto prereq : prerequisites){
            adj[prereq[0]].push_back(prereq[1]);
        }

        // create a visited array: 0 - unvisited, 1 - visited, 2 - fully explored, no cycle confirmed
        vector<int> visited(numCourses, 0);
        
        // visit all possible courses
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(!dfs(i, visited, adj)) return false;
            }
        }

        return true;
    }
};
