class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> hm;
        for(auto ch : s){
            hm[ch]++;
        }

        // use a maxheap to prioritize placing down characters with bigger frequency
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> maxheap;
        for(auto [ch, freq] : hm){
            maxheap.push({freq, ch});
        }

        string result = "";
        while(!maxheap.empty()){
            char ch = maxheap.top().second;
            int freq = maxheap.top().first;
            maxheap.pop();

            if(result[result.length() - 1] == ch) {
                if(!maxheap.empty()){
                    char sameCh = ch;
                    int sameFreq = freq;

                    ch = maxheap.top().second;
                    freq = maxheap.top().first;
                    maxheap.pop();

                    if(sameCh == ch) return "";

                    maxheap.push({sameFreq, sameCh});
                } else {
                    return "";
                }
            }

            result.push_back(ch);
            freq--;

            if(freq > 0) maxheap.push({freq, ch});
        }

        return result;
    }
};