class Solution {
public:
    double trimMean(vector<int>& arr) {
        deque<int> vec;
        for(int i = 0 ; i<arr.size() ; i++){
            vec.push_back(arr[i]);
        }
        int erasing = arr.size()/20;
        sort(vec.begin(),vec.end());
        for(int i = 0 ; i<erasing ; i++){
            vec.pop_back();
            vec.pop_front();
        }
        
        int sum = accumulate(vec.begin(),vec.end(),0);
        return sum*1.0/vec.size();
        
    }
};