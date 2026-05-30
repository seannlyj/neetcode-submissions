class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto i : nums){
            minheap.push(i);
        }

        int popAmount = minheap.size() - k;

        while(popAmount > 0){
            minheap.pop();
            popAmount--;
        }
    }
    
    int add(int val) {
        minheap.push(val);

        if(minheap.size() > k)
            minheap.pop();

        return minheap.top();
    }
};
