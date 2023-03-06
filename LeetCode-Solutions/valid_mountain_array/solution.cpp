class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int idx = -1;
        for(int i = 1 ; i<arr.size()-1 ; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                idx = i;
                break;
            }
        }
        if(idx==-1) return false;
        
        for(int i = 0 ; i<idx ; i++){
            if(arr[i]>=arr[i+1]) return false;
        }
        
        for(int i = idx ; i<arr.size()-1 ; i++){
            if(arr[i]<=arr[i+1]) return false;
        }
            
        return true;
    }
};