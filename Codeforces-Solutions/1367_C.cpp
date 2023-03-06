#include <bits/stdc++.h>


using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        string s;
        cin>>s;
        int count = k+1;
        int sol = 0;

        for(int i = 0 ;i<n ;){
            if(s[i]=='1'){
                i+=k+1;
                count = k+1;
            }else{
                count--;
                if(count==0){
                    sol++;
                    i++;
                    count = k+1;
                }else{
                    if(i==n-1){
                        sol++;
                    }
                    i++;
                }
            }
        }
        cout<<sol<<endl;
    }
    return 0;
}