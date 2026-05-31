class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            int height = min(heights[l], heights[r]);  
            int distance = r - l;
            cout<<"height = "<<height << ", distance = "<<distance<<endl;


            int area = distance * height;

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
