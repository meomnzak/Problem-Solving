#include <bits/stdc++.h>


using namespace std;



int main(){
    map<int,int> m;
    int n;
    cin>>n;
    int count = 0;
    int maxx = 0;
    int num;
    for(int i = 0 ; i<n+n ; i++){
        cin>>num;
        if(m[num]==0){
            m[num] =1;
            count++;
        }else{
            count--;
        }
        maxx = max(count,maxx);
    }
    cout<<maxx<<endl;
    return 0;
}