class MyCircularQueue {
private:
    struct ListNode {
        ListNode* next;
        int val;

        ListNode(int v, ListNode* n) : val(v), next(n) {}
    };

    ListNode* root;
    ListNode* tail;
    int size = 0;
    int currSize = 0;

public:
    MyCircularQueue(int k) {
        root = new ListNode(-1, nullptr);
        tail = root;
        ListNode* node = root;

        for(int i = 1; i < k; i++){
            ListNode* newNode = new ListNode(-1, nullptr);
            node->next = newNode;
            node = node->next;
        }
        node->next = root;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isEmpty()){
            tail->val = value;
            currSize++;
            return true;
        } else {
            if(tail->next->val == -1){
                tail->next->val = value;
                tail = tail->next;
                currSize++;
                return true;
            }
        }

        return false;
    }
    
    bool deQueue() {
        if(root->val == -1) {
            return false;
        }
        root->val = -1;

        if(root->next->val != -1)
            root = root->next;

        currSize--;
        return true;
    }
    
    int Front() {
        return root->val;
    }
    
    int Rear() {
        return tail->val;
    }
    
    bool isEmpty() {

        return currSize == 0;
    }
    
    bool isFull() {
        return currSize == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */