#include <bits/stdc++.h>


using namespace std;
int main(){
    string s;
    int t;
    cin>>t;
    int n;
    while(t--){
        bool flag = false;
        cin>>n;
        cin>>s;
        int ans = 0;
        int cur = 0;
        int pos = 0;
        for(int  i = 0 ; i<n ; i++){
            if(s[i]=='A'){
                pos = i;
                flag = true;
                break;
            }
        }
        if(flag){
            for(int i = pos ; i<n; i++){
                if(s[i]=='A'){
                    ans = max(ans,cur);
                    flag= true;
                    cur = 0;
                }else{
                    cur++;
                }
            }
             cout<<max(ans,cur)<<endl;
        }else{
            cout<<0<<endl;
        }
        
           

    }
    return 0;
}