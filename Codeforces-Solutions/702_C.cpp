#include <bits/stdc++.h>


using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> cities(n);
    vector<int> towers(m);
    for(int i = 0 ; i<n ; i++){
        cin>>cities[i];
    }
    
    for(int i = 0 ; i<m ; i++){
        cin>>towers[i];
    }
    int distAfter;
    int distBefore;
    int dist;
    int ans = 0;
    for(int i = 0 ; i<n; i++){
        int curr = lower_bound(towers.begin(),towers.end(),cities[i])-towers.begin();
        if(curr==m){
            distAfter = towers[m-1];
        }else{
            distAfter= towers[curr];
        }
        if(curr==0){
            distBefore = towers[0];
        }else{
            distBefore = towers[curr-1];
        }
        dist = min(abs(cities[i]-distBefore),abs(cities[i]-distAfter));
        ans = max(ans,dist);
    }
    cout<<ans<<endl;
    return 0;
}