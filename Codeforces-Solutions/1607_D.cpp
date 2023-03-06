#include <bits/stdc++.h>


#define endl '\n'


using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num;
        vector<int> vec;
        for (int i = 0; i <n; ++i) {
            cin>>num;
            vec.push_back(num);
        }
        string s;
        cin>>s;
        vector<int> blue;
        vector<int> red;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i]=='B'){
                blue.push_back(vec[i]);
            }else{
                red.push_back(vec[i]);
            }
        }
        sort(red.begin(),red.end(),greater<int>());
        int posMaxi = n;
        map<int,int> mp;
        bool flag = true;
        for (int i = 0; i < red.size(); ++i) {
            if(red[i]>posMaxi){
                flag = false;
                break;
            }else{
                mp[posMaxi] = 1;
                posMaxi--;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
        }else{
            sort(blue.begin(),blue.end());
            int posMini = 1;
            for (int i = 0; i < blue.size(); ++i) {
                if(blue[i]<posMini){
                    flag = false;
                    break;
                }else{
                    mp[posMini] = 1;
                    posMini++;
                }
            }
            if(!flag){
                cout<<"NO"<<endl;
            }else{
                if(mp.size()==n){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
        }

    }
}