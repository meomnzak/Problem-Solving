#include <bits/stdc++.h>


using namespace std;
int main(){
    int init,n;
    cin>>init>>n;
    vector<pair<int,int>> vec;
    int num1;
    int num2;
    for(int i = 0 ; i<n; i++){
        cin>>num1>>num2;
        vec.push_back(make_pair(num1,num2));
    }

    bool flag = true;
    sort(vec.begin(),vec.end());
    for(int i = 0 ;i<n ; i++){
        if(init>vec[i].first){
            init+=vec[i].second;
        }else{
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}