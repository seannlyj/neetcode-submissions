/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        // Use an unordered_map to keep track of next/random in old linked list
        // Node, <Next, Random>
        // Node, ID represents the respective ID for their individual nodes
        unordered_map<Node*, pair<Node*, Node*>> oldUM;
        unordered_map<int, Node*> oldID;
        unordered_map<Node*, int> oldNode;

        // new LinkedList
        unordered_map<int, Node*> newID;
        Node* node = head;

        int id = 0;
        while(node != nullptr){
            oldUM[node] = {node->next, node->random};
            oldID[id] = node;
            oldNode[node] = id;

            // Create new node and assign their respective UI
            Node* newNode = new Node(node->val);
            newID[id] = newNode;
            cout<<"Created new node "<<newNode->val <<" at ID: " << id<<endl;
            
            id++;
            node = node->next;
        }

        // store the new unordered_map
        //unordered_map<Node*, pair<Node*, Node*>> newUM;
        for(auto &[key, val] : newID){
            // using the id, find the old node's next and random
            Node *oldCurr = oldID[key];
            Node *oldNext = oldUM[oldCurr].first;
            Node *oldRandom = oldUM[oldCurr].second;

            Node* newNext = nullptr;
            Node* newRandom = nullptr;

            if(oldNext != nullptr){
                // get id of old next
                int nextID = oldNode[oldNext];
                newNext = newID[nextID];
            }

            if(oldRandom != nullptr){
                int randomID = oldNode[oldRandom];
                newRandom = newID[randomID];
            }

            Node* newNode = val;
            newNode->next = newNext;
            newNode->random = newRandom;
        }

        

        return newID[0];

    }
};
