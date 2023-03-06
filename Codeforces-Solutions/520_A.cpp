#include <bits/stdc++.h>


using namespace std;
int main(){
    map<char,int> m;
    for(int i = 0 ; i<26 ; i++){
        m['a'+i] = 0;
    }
    string line;
    int n;
    cin>>n;
    cin>>line;
    if(n<26){
        cout<<"NO"<<endl;
    }else{
        for(int i = 0 ; i<line.length() ; i++){
            m[tolower(line[i])]+=1;
        }
        bool flag = true;
        for(auto it = m.begin() ; it != m.end() ; it++){
            if(it->second == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}