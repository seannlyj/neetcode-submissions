class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        map<int, pair<int, int>> hm; //id : <enqueue time : process time> 
        
        int id = 0;
        for(auto task : tasks){
            hm[id] = {task[0], task[1]};
            id++;
        }

        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        
        // get earliest timing first
        int earliestID = 0;
        for(auto [newTaskID, task] : hm) {
            if(hm[earliestID].first > task.first) earliestID = newTaskID;
        }

        // Push all tasks that have the earliestTiming into heap
        long long time = (long long)hm[earliestID].first;
        vector<int> toErase;
        for(auto [newTaskID, task] : hm) {
            if(task.first <= time) {
                minheap.push({task.second, newTaskID});
                toErase.push_back(newTaskID);
            }
        }

        for(auto eraseID : toErase){
            hm.erase(eraseID);
        }

        while(!minheap.empty()){
            long long processingTime = minheap.top().first;
            int id = minheap.top().second;

            minheap.pop();  
            time += processingTime;
            result.push_back(id);

            // look through hashmap for any task where enqueueTime <= time
            long long nextMinEnqueueTime = LLONG_MAX;
            vector<int> toErase;
            for(auto [newTaskID, task] : hm) {
                if(task.first <= time) {
                    minheap.push({task.second, newTaskID});
                    toErase.push_back(newTaskID);
                }
                if(task.first < nextMinEnqueueTime) nextMinEnqueueTime = task.first;
            }


            for(auto eraseID : toErase){
                hm.erase(eraseID);
            }

            // if there are no more tasks, we need to skip to the next task with the lowest enqueue time
            if(minheap.empty()){
                time = nextMinEnqueueTime;
                for(auto [newTaskID, task] : hm) {
                    if(task.first <= time) {
                        minheap.push({task.second, newTaskID});
                        hm.erase(newTaskID);
                    }
                }
            }


        }

        return result;
    }
};