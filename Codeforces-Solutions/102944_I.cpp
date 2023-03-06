#include <bits/stdc++.h>


#define endl '\n'


using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        map<char,int> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]] = i;
        }
        string word;
        cin>>word;
        int summ = 0;
        for (int i = 1; i < word.size(); ++i) {
            summ+=abs(mp[word[i]]-mp[word[i-1]]);
        }
        cout<<summ<<endl;
    }
}