class StockSpanner {
private:
    stack<int> s;
public:
    StockSpanner() { }
    
    int next(int price) {
        int days = 1;

        stack<int> copy = s;
        while(!copy.empty()){
            int p = copy.top(); copy.pop();

            if(price >= p){
                days++;
            } else {
                break;
            }
        }

        s.push(price);
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */