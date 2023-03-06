class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> ans;
        deque<int> de;
        for(int i = 0 ; i<=n ; i++){
            de.push_back(i);
        }
        for(int i = n-1 ; i>=0 ; i--){
            if(s[i]=='I'){
                ans.push_back(de.back());
                de.pop_back();
            }else{
                ans.push_back(de.front());
                de.pop_front();
            }
        }
        ans.push_back(de.back());
        reverse(ans.begin(),ans.end());
        return ans;
    }
};