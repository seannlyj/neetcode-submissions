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
    ListNode* reverseList(ListNode* head) {
        stack<int> s;
        ListNode* node = head;

        while(node != nullptr){
            cout<<"Pushing " <<node->val <<endl;
            s.push(node->val);
            node = node->next;
        }

        node = head;
        while(!s.empty()){
            int val = s.top();
            node->val = val;
            node = node->next;
            s.pop();


        }

        return head;
    }
};
