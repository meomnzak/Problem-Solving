#include <bits/stdc++.h>


using namespace std;
int main(){
    string s;
    cin>>s;
    string temp = "";
    int count = 0;
    int num;
    int go = 0;
    for(int i = 0 ; i<s.size() ; i++){
        go++;
        temp+=s[i];
        num = stoi(temp);
        if(num%3==0 || s[i]%3==0 || go==3){
            count++;
            temp = "";
            go = 0;
        }
    }
    cout<<count<<endl;
    return 0;
}