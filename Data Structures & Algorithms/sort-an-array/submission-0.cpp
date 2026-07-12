class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> l(n1), r(n2);

        for(int i = 0; i < n1; i++) l[i] = arr[left + i];
        for(int j = 0; j < n2; j++) r[j] = arr[mid + 1 + j];

        int i = 0, j = 0;
        int k = left;

        // merge temp vectors back into arr[left...right]
        while(i < n1 && j < n2){
            if(l[i] <= r[j]){
                arr[k] = l[i];
                i++;
            } else {
                arr[k] = r[j];
                j++;
            }
            k++;
        }

        //copy remaining elements of l and r if there is any
        while(i < n1){
            arr[k] = l[i];
            i++;
            k++;
        }

        while(j < n2){
            arr[k] = r[j];
            j++;
            k++;
        }
    }

    void mergesort(vector<int>& arr, int left, int right){
        if(left >= right) return;

        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);        
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> result(nums);
        mergesort(result, 0, result.size() - 1);
        return result;
    }
};