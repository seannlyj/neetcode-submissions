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
 
 // 66 + 9 = 75
 // l1: 6 -> 6
 // l2: 9

 // 9 + 6 = 15 (more than 1 digit)
 // 15 % 10 = 5 this will be the first element in the new linked list
 // carry over one when we go to 6, add to 7
 // result list: 5 -> 7

// 99 + 999 = 1098
// l1: 9 -> 9, l2: 9 -> 9 -> 9
// 9 + 9 = 18 (>10)
// 18 % 10 = 8, carryOver = 1
// l3: 8, l1: 9, l2: 9 -> 9

// 9 + 9 + carryOver = 18 + 1 = 19 (>10)
// 19 % 10 = 9, carryOver = 1
// l3: 8 -> 9, l1 empty, l2 = 9

// 9 + caryOver = 10 (>=10)
// 10 % 10 = 0, carry over = 1
// l3: 8 -> 9 -> 0

// 1
// l3: 8 -> 9 -> 0 -> 1

class Solution {
public:
    ListNode* addCurrentDigit(ListNode* l1, ListNode* l2, int carryOver){
        if(l1 == nullptr && l2 == nullptr){
            if(carryOver > 0) {
                ListNode* node = new ListNode(carryOver);
                return node;
            }
            return nullptr;
        }

        int val = carryOver;
        if(l1 != nullptr) val += l1->val;
        if(l2 != nullptr) val += l2->val;

        if(val >= 10) carryOver = 1;
        else carryOver = 0;
        
        val %= 10;

        ListNode* node = new ListNode(val);
        if(l1 && l2) node->next = addCurrentDigit(l1->next, l2->next, carryOver);
        else if(l1) node->next = addCurrentDigit(l1->next, nullptr, carryOver);
        else node->next = addCurrentDigit(nullptr, l2->next, carryOver);

        return node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addCurrentDigit(l1, l2, 0);
    }
};
