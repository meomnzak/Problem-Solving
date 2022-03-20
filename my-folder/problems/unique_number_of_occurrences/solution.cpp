class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i<arr.size() ; i++){
            mp[arr[i]]++;
        }
        unordered_map<int,int> freq;
        for(auto it = mp.begin() ; it!=mp.end() ; it++){
            freq[it->second]++;
            if(freq[it->second]==2) return false;
        }
        return true;
    }
};