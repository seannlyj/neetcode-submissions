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
        cout<<"Trying to get " << key <<" at time " << time <<endl;
        if(um.count(key)){
            um[key].second = time;
            cout<<endl;
            return um[key].first;
        }
        cout<<endl;
        return -1;
    }
    
    void put(int key, int value) {
        time++;

        cout<<"Putting " << value << " into " << key <<" at time "<<time <<endl;

        // check if key exists
        if(um.count(key)){
            cout<<key << " already exists, we update"<<endl;
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
            cout<<"Too many elements in hashmap, we remove "<<oldestKey<<endl;

            if(um.count(oldestKey)) um.erase(oldestKey);

            um[key] = {value, time};

        } else {
            // not exceeding, insert normally
            cout<<"Not exceeding hashmap and doesn't exist, insert normally"<<endl;
            um[key] = {value, time};
        }

        cout<<endl;
    }
};
