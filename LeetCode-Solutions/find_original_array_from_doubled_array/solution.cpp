class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> mp;
        vector<int> vec = changed;
        int n = changed.size();
        for(int i = 0 ; i<n ; i++){
            mp[vec[i]]++;
        }
        sort(vec.begin(),vec.end());
        vector<int> ans;
        for(int i = 0 ; i<n ; i++){
            if(mp[vec[i]]==0) continue;
            mp[vec[i]]--;
            int doubleta = vec[i]*2;
            if(mp[doubleta]==0) return {};
            ans.push_back(vec[i]);
            mp[doubleta]--;
        }
        
        return ans;
    }
};