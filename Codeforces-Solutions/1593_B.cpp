#include <bits/stdc++.h>


#define endl '\n'



using namespace std;

typedef long long ll;




int main() {
    int t;
    cin>>t;
    while(t--){
       string s;
       cin>>s;
       bool flag = false;
       int pos = 1e9;
       int n = s.size();
        for (int i = s.size(); i >=0 ; --i) {
            if(s[i]=='0' && flag){
                pos = min(pos,n-i-2);
                break;
            }else if(s[i]=='0'){
                flag = true;
            }
        }
        flag = false;
        for (int i = s.size(); i >=0 ; --i) {
            if(s[i]=='7' && flag){
                pos = min(pos,n-i-2);
                break;
            }else if(s[i]=='5'){
                flag = true;
            }
        }
        flag = false;
        for (int i = s.size(); i >=0 ; --i) {
            if(s[i]=='5' && flag){
                pos = min(pos,n-i-2);
                break;
            }else if(s[i]=='0'){
                flag = true;
            }
        }
        flag = false;
        for (int i = s.size(); i >=0 ; --i) {
            if(s[i]=='2' && flag){
                pos = min(pos,n-i-2);
                break;
            }else if(s[i]=='5'){
                flag = true;
            }
        }
        cout<<pos<<endl;
    }
}