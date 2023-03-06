#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> vec;
    for(int i = 1 ; i<=n/i ; i++){
        if(n%i==0){
            vec.push_back(i);
            if(i!=n/i){
                vec.push_back(n/i);
            }
        }
    }
    sort(vec.begin(),vec.end());
    for(int i = 0 ; i<vec.size() ; i++){
        reverse(s.begin(),s.begin()+vec[i]);
    }
    cout<<s<<endl;
    return 0;
}