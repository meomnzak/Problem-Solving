#include <bits/stdc++.h>


using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> vec(n);
    vector<long long> sum(n);
    vector<long long> sorted(n);
    vector<long long> sumSort(n);
    for(long long i = 0 ; i<n ; i++){
        cin>>vec[i];
    }
    sum[0] = vec[0];
    for(long long i = 1 ; i<n; i++){
        sum[i] = sum[i-1] + vec[i];
    }
    sorted = vec;
    sort(sorted.begin(),sorted.end());
    sumSort[0] = sorted[0];
    for(long long i = 1 ; i<n; i++){
        sumSort[i] = sumSort[i-1] + sorted[i];
    }
    long long q;
    cin>>q;
    long long type;
    long long l;
    long long r;
    while(q--){
        cin>>type>>l>>r;
        l-=1;
        r-=1;
        if(type==1){
            if(l==0){
                cout<<sum[r]<<endl;
            }else{
                cout<<sum[r]-sum[l-1]<<endl;
            }
        }else{
            if(l==0){
                cout<<sumSort[r]<<endl;
            }else{
                cout<<sumSort[r]-sumSort[l-1]<<endl;
            }
        }
    }
    return 0;
}