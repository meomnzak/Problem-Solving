#include <bits/stdc++.h>


#define endl '\n'



using namespace std;

typedef long long ll;





char arr[3][102];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for (int i = 0; i < 2; ++i) {
            string s;
            cin>>s;
            for (int j = 0; j < n; ++j) {
                arr[i][j] = s[j];
            }
        }
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if(arr[0][i]=='1' && arr[1][i]=='1'){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }



}