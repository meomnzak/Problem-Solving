#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      deque<int> vec;
      int num;
       for (int i = 0; i < n; ++i) {
           cin>>num;
           vec.push_back(num);
       }
       if(vec[0]==n){
           vec.pop_front();
       }else if(vec[n-1]==n){
           vec.pop_back();
       }else{
           cout<<-1<<endl;
           continue;
       }
       reverse(vec.begin(),vec.end());
       for (int i = 0; i < vec.size(); ++i) {
           cout<<vec[i]<<" ";
       }
       cout<<n<<endl;
   }


    return 0;

}
