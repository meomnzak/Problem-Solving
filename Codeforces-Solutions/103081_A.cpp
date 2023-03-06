#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   int t;
   cin>>t;
   while(t--){
       string s;
       cin>>s;
       if((s[s.size()-1]-'0')%2==0){
           cout<<0<<endl;
       }else if((s[0]-'0')%2==0){
           cout<<1<<endl;
       }else{
           bool flag = false;
           for (int i = 0; i < s.size(); ++i) {
               if((s[i]-'0')%2==0){
                   flag = true;
                   break;
               }
           }
           if(flag){
               cout<<2<<endl;
           }else{
               cout<<-1<<endl;
           }
       }
   }


    return 0;

}
