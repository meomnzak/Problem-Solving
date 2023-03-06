#include <bits/stdc++.h>


#define endl '\n'


using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        ll x,n;
        cin>>x>>n;
        ll pos = x;
        if(n<=6){
            for (ll i = 1; i <=n ; ++i) {
                if(pos%2==0){
                    pos-=i;
                }else{
                    pos+=i;
                }
            }
            cout<<pos<<endl;
        }else{

            if(x%2==0){
                if(n%2==0){
                    if(n%4==0){
                        cout<<x<<endl;
                    }else{
                        cout<<x+1<<endl;
                    }
                }else{
                    if((n-1)%4==0){
                        cout<<(x-(4ll*(((n-2)/4)+1)))-1<<endl;
                    }else{
                        cout<<(x+(4ll*(((n-2)/4)+1)))<<endl;
                    }
                }
            }else{
                if(n%2==0){
                    if(n%4==0){
                        cout<<x<<endl;
                    }else{
                        cout<<x-1<<endl;
                    }
                }else{
                    if((n-1)%4==0){
                        cout<<(x+(4ll*(((n-2)/4)+1)))+1<<endl;
                    }else{
                        cout<<(x-(4ll*(((n-2)/4)+1)))<<endl;
                    }
                }
            }
        }

    }




}