class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int> mp;
        for(int i = 0 ; i<t.size() ; i++){
            mp[t[i]]++;
        }
        map<int,int> cnt;
        int n = s.size();
        int i = 0;
        pair<int,int> ans = {-1,-1};
        int best = 1e9;
        int tot = 0;
        map<int,int> valid;
        for(int j = 0 ; j<n ; j++){
            if(mp.find(s[j])!=mp.end()){
                cnt[s[j]]++;
                if(cnt[s[j]]>=mp[s[j]]){
                    valid[s[j]] = 1;
                }
            }
            while(valid.size()==mp.size()){
                if((j-i+1)<best){
                    best = j-i+1;
                    ans = {i,best};
                }
                if(mp.find(s[i])!=mp.end()){
                    cnt[s[i]]--;
                    if(cnt[s[i]]<mp[s[i]]){
                        valid.erase(s[i]);
                    }
                }
                i++;
            }
        }
        if(ans.first==-1){
            return "";
        }else{
            return s.substr(ans.first,ans.second);
        }
    }
};