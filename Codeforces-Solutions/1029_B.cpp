#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec;
    int num;
    for(int  i = 0; i<n ; i++){
        cin>>num;
        vec.push_back(num);
    }
    int count = 1;
    int l,r;
    l = 0 ; r = 0;
    int maxx = 1;
    while(l<n-1){
        while(r<n-1 && vec[r]*2>=vec[r+1]){
            count++;
            r++;
        }
        maxx = max(count,maxx);
        count = 1;
        r++;
        l = r;
    }
    cout<<maxx<<endl;
    return 0;
}