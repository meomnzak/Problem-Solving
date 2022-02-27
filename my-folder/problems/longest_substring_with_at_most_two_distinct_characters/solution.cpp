class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        int n = s.size();
        int i = 0;
        map<char,int> mp;
        int maxi = 0;
        for(int j = 0 ; j<n ; j++){
            mp[s[j]]++;
            while(mp.size()>2){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};