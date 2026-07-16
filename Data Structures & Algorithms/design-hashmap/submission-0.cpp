class MyHashMap {
private:
    vector<pair<int, int>> hm;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(int i = 0; i < hm.size(); i++){
            auto [k, v] = hm[i];
            if(k == key){
                hm[i].second = value;
                return;
            }
        }

        hm.push_back({key, value});
    }
    
    int get(int key) {
        for(auto [k, v] : hm){
            if(k == key) return v;
        }

        return -1;
    }
    
    void remove(int key) {
        int index = -1;
        for(int i = 0; i < hm.size(); i++){
            auto [k, v] =  hm[i];
            if(k == key){
                index = i;
                break;
            }
        }

        if(index != -1)
            hm.erase(hm.begin() + index);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */