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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr) return head;

        int step = 1;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* start = nullptr;
        ListNode* end = nullptr;
        while(curr != nullptr){
            if(step + 1 == left){
                start = curr;
            }

            if(step == left){
                end = curr;
            }

            if(step > right) {
                break;
            }

            if(step >= left && step <= right){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;

            } 
            else {
                curr = curr->next;
            }

            step++;
        }

        if(start){
            start->next = prev;
        }
        if(end){
            //cout<<end->val<<endl;
            end->next = curr;
        }

        return (start == nullptr ? prev : head);
    }
};