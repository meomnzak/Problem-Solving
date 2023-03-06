#include <bits/stdc++.h>


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> vec;
        int n;
        cin>>n;
        int num;
        for(int i = 0 ; i<n ; i++){
            cin>>num;
            vec.push_back(num);
        }
        long long sum1 = 0;
        long long sum2 = 0;
        sum1+=vec[0];
        int count = 1;
        int l = 1, r = n-1; 
        long long local1  = 0;
        long long local2 = 0;
        long long pre1 = vec[0];
        long long pre2 = 0;
            while(l<=r){
                while ( l <= r && local2 <=pre1){
                   local2+=vec[r];
                   r--;
                }
                count++;
                sum2+=local2;
                pre2 = local2;
                if(l>r){
                    break;
                }
                while ( l <= r && local1 <=pre2){
                   local1+=vec[l];
                   l++;
                }
                count++;
                
                sum1+=local1;
                pre1 = local1;
                if(l>r){
                    break;
                }
                local1 = 0;
                local2 = 0;
            }
            cout<<count<<" "<<sum1<<" "<<sum2<<endl;
    }
    return 0;
}