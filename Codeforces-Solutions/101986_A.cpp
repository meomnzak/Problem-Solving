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
        int abS = 0;
        int baS = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            abS+=(s[i]=='a'&&s[i+1]=='b');
            baS+= (s[i]=='b'&&s[i+1]=='a');
        }
        if(abS == baS){
            cout<<s<<endl;
        }else{
            if(s[0]=='a'){
                s[0] = 'b';
            }else{
                s[0] = 'a';
            }
            cout<<s<<endl;
        }
    }
}