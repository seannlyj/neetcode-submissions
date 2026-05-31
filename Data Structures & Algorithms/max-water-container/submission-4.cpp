class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            int area = min(heights[l], heights[r]) * (r-l);


            if(area > max)
            {
                max = area;
                //l++;
                //r--;
            }

            if(heights[l] > heights[r]){
                r--;
            } else {
                l++;
            }
        }

        return max;
    }
};
