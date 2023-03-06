class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        int maxi = 0;
        int num = -1;
        for(int i = 0 ; i<arr.size() ; i++){
            mp[arr[i]]++;
            if(mp[arr[i]]>maxi){
                maxi = mp[arr[i]];
                num = arr[i];
            }
        }
        return num;
    }
};