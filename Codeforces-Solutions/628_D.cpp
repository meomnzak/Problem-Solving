#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;


int m,d;
string a,b;
const int MOD = 1e9+7;

int meme[2002][2002][2][2];

int solve(int idx, int summ , int aa , int bb){
    if(idx==a.size()) return (summ==0);
    int &ret = meme[idx][summ][aa][bb];
    if(~ret) return ret;
    ret = 0;
    for (int i = 0; i <=9 ; ++i) {
        if((idx%2==1 && i==d) || (idx%2==0 && i!=d)){
            if(!aa && i<a[idx]-'0') continue;
            if(!bb && i>b[idx]-'0') continue;
            ret = (ret+solve(idx+1,(summ*10+i)%m,aa||i>(a[idx]-'0'),bb||i<(b[idx]-'0')))%MOD;
        }
    }
    return ret;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin>>m>>d;
    cin>>a>>b;
    memset(meme,-1,sizeof(meme));
    cout<<solve(0,0,0,0)<<endl;
}