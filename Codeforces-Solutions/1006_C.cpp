#include <bits/stdc++.h>


using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long> vec;
    long long num;
   for(long long i = 0 ; i<n; i++){
        cin>>num;
        vec.push_back(num);
    }
    long long l = 0;
    long long r = n-1;
    long long sum1 = vec[l];
    long long sum2 = vec[r];
    long long temp = 0;
    while(l<r){
        if(sum1==sum2){
            temp = sum1;
            l++;
            if(l<r){
                sum1+=vec[l];
            }
        }else if(sum1<sum2){
            l++;
            if(l<r){
                sum1+=vec[l];
            }
        }else{
             r--;
            if(l<r){
                sum2+=vec[r];
            }
        }
    }
    cout<<temp<<endl;
    return 0;
}