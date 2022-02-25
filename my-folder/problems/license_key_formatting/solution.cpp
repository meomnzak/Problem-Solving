class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        string out = "";
        int cnt = 0;
        for(int i = n-1 ; i>= 0 ; i--){
            if(s[i]=='-') continue;
            if(isalpha(s[i])){
                s[i] = toupper(s[i]);
            }
            out+=s[i];
            cnt++;
            if(cnt==k){
                cnt = 0;
                out+='-';
            }
        }
        if(out.back()=='-') out.pop_back();
        reverse(out.begin(),out.end());
        return out;
    }
};