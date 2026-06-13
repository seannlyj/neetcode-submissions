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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int size = 0;
        while(node != nullptr){
            size++;
            node = node->next;
        }

        int reverseN = size - n;
        int counter = -1;

        cout<<"Size: " << size <<", n = "<< n <<", reverseN = "<< reverseN <<endl;

        ListNode* dummy = new ListNode(0, head);
        while(dummy != nullptr){
            if(counter + 1 == reverseN){
                cout<<"Next node needs to be removed: " << dummy->next->val << endl;
                ListNode* toRemove = dummy->next;
                dummy->next = toRemove->next;

                if(toRemove == head){
                    head = toRemove->next;
                }
            }

            dummy = dummy->next;
            counter++;
        }

        return head;
    }
};
