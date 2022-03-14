class Solution {
public:
    
    int binarySearch(vector<int> & arr,int low, int high){
        int res = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
                res = mid;
                return res;
            }else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return res;
    }
    
    
    int peakIndexInMountainArray(vector<int>& arr) {
        return binarySearch(arr,1,arr.size()-2);
    }
};