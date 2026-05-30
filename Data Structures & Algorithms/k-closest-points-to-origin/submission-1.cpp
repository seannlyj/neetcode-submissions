class Solution {
public:
    int distance(array<int, 2> a, array<int, 2> b){
        int x = a[0] - b[0];
        int y = a[1] - b[1];

        return (x*x) + (y*y);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, less<pair<int, vector<int>>>> maxheap;

        for(vector<int> point : points){
            // calculate distance
            int dist = distance({0,0}, {point[0], point[1]});
            maxheap.push({dist, point});

            cout<<"["<<point[0] << "," <<point[1]<<"] = " << dist<<endl;

            if(maxheap.size() > k)
                maxheap.pop();
        }

        for(int i = 0; i < k; i++){
            pair<int, vector<int>> top = maxheap.top();
            result.push_back(top.second);
            maxheap.pop();
        }

        return result;
    }
};
