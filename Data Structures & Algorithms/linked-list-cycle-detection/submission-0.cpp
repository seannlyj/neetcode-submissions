/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> uset;

        ListNode* node = head;

        while(node != nullptr){
            if(uset.count(node)) return true;
        
            uset.insert(node);
            node = node->next;
        }

        return false;
    }
};
