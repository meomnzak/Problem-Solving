class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> vec;
        for(int i = 0 ; i<arr.size() && vec.size()<arr.size() ; i++){
            vec.push_back(arr[i]);
            if(arr[i]==0 && vec.size()<arr.size()){
                vec.push_back(0);
            }
        }
        arr = vec;
    }
};