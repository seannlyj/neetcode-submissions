class Solution {
//fixed size sliding window of size k
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        //build first window
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        int avg = sum / k;
        int result = 0;

        if(avg >= threshold) result++;

        for(int i = k; i < arr.size(); i++){
            sum -= arr[i - k];
            sum += arr[i];
            avg = sum / k;
            if(avg >= threshold) result++;
        }

        return result;
    }
};