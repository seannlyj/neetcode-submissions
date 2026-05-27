/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void recursive_dfs(Node* node, Node* newNode, unordered_map<Node*, Node*>& visited){
        if(node == nullptr) return;

        // if node is already visited, exit function
        if(visited.count(node)) return;

        // add node to visited with newNode for reference
        visited.insert({node, newNode});

        // for each neighbor found in node
        for(auto& neighbor : node->neighbors) {
            Node* newNeighbor;
            // if the neighbor is already visited
            if(visited.find(neighbor) != visited.end()) {
                // get the neighbor and assign the newly created node as its neighbor
                newNeighbor = visited[neighbor];
                newNode->neighbors.push_back(newNeighbor);
            } else {
                // if neighbor is not visited, create a new neighbor
                newNeighbor = new Node(neighbor->val); 
                newNode->neighbors.push_back(newNeighbor);
                recursive_dfs(neighbor, newNeighbor, visited);
            }


        }
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> visited;
        Node* newRoot = new Node(node->val);

        recursive_dfs(node, newRoot, visited);

        return newRoot;
    }
};
