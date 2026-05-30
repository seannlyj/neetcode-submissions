class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i : stones) { 
            pq.push(i);
        }

        int remainingStone = 0;
        while(pq.size() > 1) {
            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            int s3 = s1 - s2;
            cout<<"Stone 1 - Stone 2 = Stone 3 | "<<s1 <<" - "<<s2 <<" = "<<s3<<endl;

            if(abs(s3) > 0){
                pq.push(abs(s3));
            }
            remainingStone = abs(s3);
        }

        if(pq.size() == 1)
            remainingStone = pq.top();

        return remainingStone;
    }
};
