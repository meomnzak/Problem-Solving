#include <bits/stdc++.h>

using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    int n,k;
    while(t--){
        long long sum = 0;
        scanf("%d%d",&n,&k);
        if(k*k>n){
            cout<<"NO"<<endl;
        }else if(k*k==n){
            cout<<"YES"<<endl;
        }else{
            sum = pow(k-1,2);
            int od= 1 + (k-1)*2;
            if((n-sum) % 2 ==1 && (n-sum >= od) && (n>sum)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
        
    }
    return 0;
}