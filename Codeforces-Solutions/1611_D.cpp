#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+7;

int par[N];

int sol[N];

int acc[N];

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int t;
   cin>>t;
   while(t--){
       memset(par,-1,sizeof(par));
       memset(sol,-1,sizeof(sol));
       memset(acc,0,sizeof(acc));
       int n;
       cin>>n;
       int num;
       for (int i = 0; i < n; ++i) {
           cin>>num;
           num--;
           par[i] = num;
       }
       int st = -1;
       bool flag = true;
       vector<int> vec;
       for (int i = 0; i < n; ++i) {
           cin>>num;
           num--;
           vec.push_back(num);
       }
       for (int i = 0; i < n; ++i) {
           if(i!=0 && sol[par[vec[i]]]==-1){
               flag = false;
               break;
           }else{
               sol[vec[i]] = st+1-acc[par[vec[i]]];
               acc[vec[i]] = sol[vec[i]]+acc[par[vec[i]]];
               st = acc[vec[i]];
           }
       }
       if(!flag){
           cout<<-1<<endl;
       }else{
           for (int i = 0; i < n; ++i) {
               cout<<sol[i]<<" ";
           }
           cout<<endl;
       }
   }


    return 0;

}
