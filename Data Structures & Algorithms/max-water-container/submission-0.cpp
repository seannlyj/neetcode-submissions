class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;

        while(l <= r) {
            // get distance between left and right elements
            int dist = r - l;

            cout<<"dist * min(heights[l], heights[r]) = " << dist << " * " << min(heights[l], heights[r]) << endl;
            res = max(res, dist * min(heights[l], heights[r]));

            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }

        return res;

    }
};
