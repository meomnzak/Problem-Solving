#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    q--;
    vector<int> vec;
    int num;
    for(int i = 0 ; i<n ; i++){
        cin>>num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end());
    if(q==-1){
        if(vec[0]==1){
            cout<<-1<<endl;
        }else{
            cout<<1<<endl;
        }
    }else if(q==n-1){
        cout<<1000000000<<endl;
    }else{
        if(vec[q]==vec[q+1]){
            cout<<-1<<endl;
        }else{
            cout<<vec[q]<<endl;
        }
    }
    return 0;
}