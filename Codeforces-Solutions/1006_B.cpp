#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int num;
    vector<pair<int,int>> gg;
    for(int i = 0 ; i<n ; i++){
        cin>>num;
        gg.push_back(make_pair(num,i));
    }
    map<int,int> indices;
    int sum = 0;
    sort(gg.begin(),gg.end());
    for(int i = n-1 ; i>n-1-k ; i--){
        sum+=gg[i].first;
        indices[gg[i].second] = 1;
    }
    cout<<sum<<endl;
    int count = 0;
    for(int i = 0 ; i<n; i++){
            count++;
            if(k==1){
                cout<<n-i;
                break;
            }
            if(indices[i] != 0){
                    cout<<count<<" ";
                    count = 0;
                    k--;
            }
    }
    cout<<endl;
    return 0;
}