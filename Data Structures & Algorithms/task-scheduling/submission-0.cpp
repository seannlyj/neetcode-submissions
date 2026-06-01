class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // use a max heap to set highest frequency first
        priority_queue<int> maxheap;
        int freq[26] = {};

        for(auto task : tasks){
            freq[(int)(task - 'A')]++;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] > 0)
                maxheap.push(freq[i]);
        }

        int curr_time = 0;
        queue<pair<int, int>> q;

        while(!maxheap.empty() || !q.empty()){
            if(!q.empty()){
                if(curr_time == q.front().second){
                    maxheap.push(q.front().first);
                    q.pop();
                }
            }

            if(!maxheap.empty()){
                int cooldown = curr_time + n + 1;
                int freq_task = maxheap.top();
                freq_task--;

                if(freq_task > 0){
                    q.push({freq_task, cooldown});
                }
                
                maxheap.pop();
            }


            curr_time++;
        }

        return curr_time;
    }
};
