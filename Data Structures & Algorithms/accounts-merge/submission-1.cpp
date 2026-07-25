class Solution {
public:
    vector<string> dfs(unordered_map<string, vector<string>> adjList, string start, unordered_set<string>& visited){
        if(visited.count(start)) return {};
        
        vector<string> result;
        stack<string> s;

        s.push(start);
        visited.insert(start);

        while(!s.empty()){
            string n = s.top(); s.pop();

            result.push_back(n);

            // traverse neighbours
            vector<string> neighbors = adjList[n];
            for(auto& neighbor : neighbors){
                if(!visited.count(neighbor)){
                    visited.insert(neighbor);
                    s.push(neighbor);
                }
            }
        }

        return result;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //store a hashmap of <email, name>
        unordered_map<string, string> hm;
        for(vector<string>& account : accounts){
            string name = account[0];
            for(int i = 1; i < account.size(); i++){
                hm[account[i]] = name;
            }
        }
        
        // build an adjList based on email
        // email1 : [email2, email3]
        // email2 : [email1]
        // email3 : [email1]
        unordered_map<string, vector<string>> adjList;
        for(vector<string>& account : accounts) {
            string firstEmail = account[1];

            if(account.size() == 2){
                adjList[firstEmail] = {};
            }

            for(int i = 2; i < account.size(); i++){
                adjList[firstEmail].push_back(account[i]);
                adjList[account[i]].push_back(firstEmail);
            }
        }

        //traverse through adjList, pushing connected components into the same vector<string>
        //need to keep track of visited node to prevent adding a duplicate email into the vector
        //once finished visiting this one, store it in the result vector<vector<string>>
        //iterate to next element in adjlist
        unordered_set<string> visited;
        vector<vector<string>> result;
        for(auto &[email, emails] : adjList){
            vector<string> v = dfs(adjList, email, visited);
            
            // once all of emails are in their respective vector<string>
            // sort it lexicographically
            // map the name to the email using hashmap<email,name>
            if(!v.empty()){
                sort(v.rbegin(), v.rend());
                v.push_back(hm[v[0]]);
                reverse(v.begin(), v.end());
                result.push_back(v);
            }
        }
    

        return result;
    }
};