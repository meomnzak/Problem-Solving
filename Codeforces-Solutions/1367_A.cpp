#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        string temp = "";
        temp+=s[0];
        for(int i = 1 ; i<s.size()-1 ; i+=2){
            temp+=s[i];
        }
        temp+=s[s.size()-1];
        cout<<temp<<endl;
    }
    return 0;
}