class Solution {
public:
    vector<int> count;
    
    void merge(vector<pair<int, int>>& arr, int low, int mid, int high) {
        vector<pair<int, int>> temp(high - low + 1);
        int i = low, j = mid + 1, k = 0;
        
        while (i <= mid && j <= high) {
            if (arr[i].first <= arr[j].first) {
                count[arr[i].second] += j - (mid + 1);
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        
        while (i <= mid) {
            count[arr[i].second] += high - mid;
            temp[k++] = arr[i++];
        }
        
        while (j <= high) {
            temp[k++] = arr[j++];
        }
        
        for (int p = 0; p < k; p++) {
            arr[low + p] = temp[p];
        }
    }
    
    void mergeSort(vector<pair<int, int>>& arr, int low, int high) {
        if (low < high) {
            int mid = (low +high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.resize(n, 0);
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        mergeSort(arr, 0, n - 1);
        return count;
    }
};