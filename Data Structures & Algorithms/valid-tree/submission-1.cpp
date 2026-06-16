class Solution {
// What defines a valid tree
//  - Having cyclic nodes
//  - Disconnected nodes
//  - Having more than one parent
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // iterative dfs
        // <node, parent>
        vector<bool> visited(n, false);
        stack<pair<int, int>> s;
        s.push({0, -1});

        while(!s.empty()){
            int node = s.top().first;
            int parent = s.top().second;
            s.pop();

            visited[node] = true;

            // for all neighbours
            for(auto& neighbour : adj[node]){
                if(parent == neighbour) continue;

                if(visited[neighbour]) return false;

                s.push({neighbour, node});
            }
        }

        // for disconnected nodes
        for(auto visit : visited){
            if (!visit) return false;
        }

        return true;
    }
};
