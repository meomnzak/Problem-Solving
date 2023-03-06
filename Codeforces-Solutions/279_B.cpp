#include <bits/stdc++.h>


using namespace std;


int main(){
    int n,time;
    scanf("%d%d",&n,&time);
    int arr[n];
    long long sum[n];
    for(int i = 0 ; i<n ;i++){
        cin>>arr[i];
    }
    sum[0] = arr[0];
    for(int i = 1 ; i<n ; i++){
        sum[i] = sum[i-1] + arr[i];
    }
    int maxx = 0;
    int found = 0;
    for(int i = 0 ; i<n ; i++){
        int res = -1;
        int low = i;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(i!=0){
                if(sum[mid]-sum[i-1] <= time){
                    res = mid;
                    low = mid+1;
                }else{
                    high = mid -1;
                }
            }else{
                if(sum[mid] <= time){
                    res = mid;
                    low = mid+1;
                }else{
                    high = mid -1;
                }
            }
        }
        if(res!=-1){
           found = res-i+1;
        }
        maxx = max(maxx,found);
    }
    printf("%d\n",maxx);
    return 0;
}