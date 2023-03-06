#include <bits/stdc++.h>


using namespace std;

bool calc(int val , int maxx,int fract){
    int num = 1;
    int sum = val;
    while(sum<maxx){
        int much = val/pow(fract,num);
        if(much==0){
            return false;
        }
        num++;
        sum+=much;
    }
    return true;
}

int main(){
    int n,k;
    cin>>n>>k;
    int low= 1;
    int high = n;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(calc(mid,n,k)){
            high = mid-1;
            ans=min(ans,mid);
        }else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}