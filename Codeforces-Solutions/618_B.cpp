#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    int arr[n][n];
    map<int,int> m;
    for(int i = 0 ; i<n; i++){
        for(int j = 0 ; j<n ; j++){
            cin>>arr[i][j];
        }
    }
    int maxx = 0;
    for(int i = 0 ; i<n; i++){
        for(int j = 0 ; j<n ; j++){
            maxx = max(maxx,arr[i][j]);
        }
        if(m[maxx]==0){
            m[maxx] = 1;
            vec.push_back(maxx);
        }else{
            vec.push_back(maxx+1);
        }
        maxx = 0;
    }
    for(int i = 0 ; i<n; i++){
            cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}