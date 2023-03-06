#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    int maxx;
    cin>>maxx;
    map<int,int> m;
    int l,r;
    while(n--){
        cin>>l>>r;
        for(int i = l ; i<=r ; i++){
            m[i] = 1;
        }
    }
    vector<int> vec;
    
    for(int i = 1 ; i<=maxx ; i++){
        if(m[i]==0){
            vec.push_back(i);
        }
    }
    if(vec.size()==0){
        cout<<0<<endl;
    }else{
        cout<<vec.size()<<endl;
        for(int i = 0 ; i<vec.size() ; i++){
            cout<<vec[i];
            if(i!=vec.size()-1){
                cout<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}