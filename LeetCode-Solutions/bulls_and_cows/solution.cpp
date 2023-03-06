class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char,int> s;
        unordered_map<char,int> g;
        for(int i = 0 ; i<secret.size() ; i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                s[secret[i]]++;
                g[guess[i]]++;
            }
        }
        for(int i = 0 ; i<=9 ; i++){
            char digit = i+'0';
            cows+=min(s[digit],g[digit]);
        }
        string ans = to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
    }
};