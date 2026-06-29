class Solution {
// Happy if:
// 1. contains ONLY a,b,c
// 2. does not contain aaa, bbb, ccc as substring (cannot be more than 2 a's in a row)
// 3. respective characters frequency = their integers provided in parameter
public:
    string longestDiverseString(int a, int b, int c) {
        int freqs[3];
        freqs[0] = a;
        freqs[1] = b;
        freqs[2] = c;

        priority_queue<pair<int, char>> maxheap;
        for(int i = 0; i < 3; i++){
            if(freqs[i] > 0)
                maxheap.push({freqs[i], i + 'a'});
        }

        string result = "";
        while(!maxheap.empty()) {
            char ch = maxheap.top().second;
            int freq = maxheap.top().first;

            maxheap.pop();
            
            // check if latest two characters are the same
            if(result.size() >= 2 && result[result.size() - 1] == ch && result[result.size() - 2] == ch){
                // if there are no other possible characters to add
                if(maxheap.empty()){
                    break;
                }

                char prevCh = ch;
                int prevFreq = freq;
                
                // pop next element and push that instead
                ch = maxheap.top().second;
                freq = maxheap.top().first;
                freq--;

                maxheap.pop();
                maxheap.push({prevFreq, prevCh});
                result.push_back(ch);
            } else {
                freq--;
                result.push_back(ch);
            }

            if(freq > 0)
                maxheap.push({freq, ch});
        }

        return result;
    }
};