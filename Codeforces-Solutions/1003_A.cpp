#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int> m;
    int num;
    int maxx = 0;
    for(int i = 0 ;i<n ; i++){
        cin>>num;
        m[num]++;
        maxx = max(maxx,m[num]);
    }
    cout<<maxx<<endl;
    return 0;
}