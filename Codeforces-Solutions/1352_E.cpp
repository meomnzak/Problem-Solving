#include <bits/stdc++.h>


using namespace std;

int arr[9000];
int more[9000];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(more,0,sizeof(more));
        int n;-
        scanf("%d",&n);
        int num;
        for(int i = 0 ;i<n ; i++){
           scanf("%d",&arr[i]);
            more[arr[i]]++;
        }
        int count = 0;
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            sum+=arr[i];
            for(int j = i+1 ; j<n ; j++){
                    sum+=arr[j];
                    if(sum>8050){
                        break;
                    }
                    if(more[sum]>=1){
                    count+=more[sum];
                    more[sum]= 0;
                }
            }
            sum = 0;
        }
        printf("%d\n",count);
    }
    return 0;
}