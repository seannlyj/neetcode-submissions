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
    void reorderList(ListNode* head) {
        if(head == nullptr) return;

        unordered_map<int, ListNode*> um;
        int n = 0;
        ListNode* node = head;
        while(node != nullptr){
            um.insert({n, node});
            node = node->next;
            n++;
        }

        node = head;
        int left = 0;
        int right = n - 1;
        while(left < right){
            um[left]->next = um[right];
            left++;
            if(left == right) break;
            um[right]->next = um[left];
            right--;
        }
        um[left]->next = nullptr;

        return;
    }
};
