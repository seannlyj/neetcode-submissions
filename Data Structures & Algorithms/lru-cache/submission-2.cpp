class LRUCache {

private:
    int capacity;
    int time;
    //store a <k, <v, t>> hashmap where v = value and t = time
    unordered_map<int, pair<int, int>> um;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        time = 0;
    }
    
    int get(int key) {
        time++;
        if(um.count(key)){
            um[key].second = time;
            return um[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        time++;

        // check if key exists
        if(um.count(key)){
            um[key] = {value, time};
            return;
        }

        // check if um will exceed capacity
        if(um.size() == capacity){

            // exceeding capacity, need to find the key with the smallest time (smaller = older)
            int oldestKey = -1;
            int oldestTime = 999;
            for(auto& [key, value] : um){
                if(oldestTime > value.second){
                    oldestKey = key;
                    oldestTime = value.second;
                }
            }

            if(um.count(oldestKey)) um.erase(oldestKey);

            um[key] = {value, time};

        } else {
            // not exceeding, insert normally
            um[key] = {value, time};
        }
    }
};
