#include <bits/stdc++.h>
 
 
using namespace std;
int main(){
    long long t;
    cin>>t;
    string s;
    long long n;
    long long k;
    while(t--){
        string s = "";
        cin>>n>>k;
        for(long long i = 0 ;i<n; i++){
            s+='a';
        }
        k--;
        long long val = (sqrt(8*k+1)-1)/2;
        long long go = (val*(val+1)/2)+1;
        long long calc = s.size()-(k-go+2);
        s[calc] = 'b';
        val++;
        long long again = (val*(val+1)/2)+1;
        long long p = s.size()-(again-go+1);
        s[p] = 'b';
        cout<<s<<endl;
    }
    return 0;
}