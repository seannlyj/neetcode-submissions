class TimeMap {
private:
    unordered_map<string, unordered_map<int, string>> hashmap;
public:
    TimeMap() {
        for(auto& [key, val] : hashmap){
            val.clear();
        }
        hashmap.clear();
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(hashmap[key].count(timestamp) == 0){
            int currTimestamp = timestamp - 1;
            while(currTimestamp >= 0){
                if(hashmap[key].count(currTimestamp)) return hashmap[key][currTimestamp];

                currTimestamp--;
            }
            return "";
        }

        return hashmap[key][timestamp];
    }
};
