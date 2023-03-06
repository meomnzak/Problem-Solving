#include <bits/stdc++.h>


#define endl '\n'

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

int freq[N];

int n;

int meme[N][3][3][3];

int meme2[N][3][3][3];

int solve(int idx, bool back, bool still, bool forward) {
    if (idx == n + 1) return 0;
    int &ret = meme[idx][back][still][forward];
    if (~ret) return ret;
    ret = 0;
    int cnt = freq[idx];
    if (cnt == 0) {
        ret = max(ret, solve(idx + 1, 0, forward, 0));
    } else {
        if (cnt >= 1) {
            ret = max(ret, (still == 0) + solve(idx + 1, 1, forward, 0));
            ret = max(ret, (forward == 0) + solve(idx + 1, 0, 1, 0));
            ret = max(ret, 1 + solve(idx + 1, 0, forward, 1));
        }
        if (cnt >= 2) {
            ret = max(ret, (still == 0) + (forward == 0) + solve(idx + 1, 1, 1, 0));
            ret = max(ret, 1 + (still == 0) + solve(idx + 1, 1, forward, 1));
            ret = max(ret, 1 + (forward == 0) + solve(idx + 1, 0, 1, 1));
        }
        if (cnt >= 3) {
            ret = max(ret, 1 + (still == 0) + (forward == 0) + solve(idx + 1, 1, 1, 1));
        }
    }

    return ret;

}


int solve2(int idx, bool back, bool still, bool forward) {
    if (idx == n + 1) return 0;
    int &ret = meme2[idx][back][still][forward];
    if (~ret) return ret;
    ret = 1e9;
    int cnt = freq[idx];
    if (cnt == 0) {
        ret = min(ret, solve2(idx + 1, 0, forward, 0));
    } else {
        if (cnt >= 1) {
            ret = min(ret, (still == 0) + solve2(idx + 1, 1, forward, 0));
            ret = min(ret, (forward == 0) + solve2(idx + 1, 0, 1, 0));
            ret = min(ret, 1 + solve2(idx + 1, 0, forward, 1));
        }
        if (cnt >= 2) {
            ret = min(ret, (still == 0) + (forward == 0) + solve2(idx + 1, 1, 1, 0));
            ret = min(ret, 1 + (still == 0) + solve2(idx + 1, 1, forward, 1));
            ret = min(ret, 1 + (forward == 0) + solve2(idx + 1, 0, 1, 1));
        }
        if (cnt >= 3) {
            ret = min(ret, 1 + (still == 0) + (forward == 0) + solve2(idx + 1, 1, 1, 1));
        }
    }

    return ret;

}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    memset(meme,-1,sizeof(meme));
    memset(meme2,-1,sizeof(meme2));
    cin>>n;
    int num;
    for (int i = 0; i < n; ++i) {
        cin>>num;
        freq[num]++;
    }
    cout<<solve2(1,0,0,0)<<" "<<solve(1,0,0,0)<<endl;
}
 