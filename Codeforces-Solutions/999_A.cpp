#include <bits/stdc++.h>


using namespace std;
int main(){
    int n;
    int k;
    cin>>n>>k;
    vector<int> vec;
    int num;
    for(int i = 0 ; i<n ; i++){
        cin>>num;
        vec.push_back(num);
    }
    int l = 0;
    int r = n-1;
    int count = 0;
    while(l<=r){
        if(vec[l]<=k){
            count++;
            l++;
        }else if(vec[r]<=k){
            count++;
            r--;
        }else{
            break;
        }
    }
    cout<<count<<endl;
    return 0;
}