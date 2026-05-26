class MinStack {
public:
    vector<int> v;
    vector<int> minV;

    MinStack() {
    }

    void push(int val) {
        v.push_back(val);
    
        if(minV.empty()) {
            minV.push_back(val);
        }
        else {
            if(minV[minV.size() - 1] > val)
                minV.push_back(val);
            else
                minV.push_back(minV[minV.size() - 1]);
        }
    }
    
    void pop() {
        v.erase(v.end() - 1);
        minV.erase(minV.end() - 1);
    }
    
    int top() {
        return v[v.size() - 1];
    }
    
    int getMin() {
        return minV[minV.size() - 1];
    }
};
