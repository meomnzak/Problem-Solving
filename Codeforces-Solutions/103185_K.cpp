#include <bits/stdc++.h>


#define endl '\n'


using namespace std;

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin>>n;
    int num;
    deque<int> vec;
    for (int i = 0; i < n; ++i) {
        cin>>num;
        vec.push_back(num);
    }
    bool flag = false;
    int lst = -1;
    vector<char> sol;
    while(vec.size()>0){
        if(vec.front()<=lst&&vec.back()<=lst){
            break;
        }
        if(vec.back()<=lst){
            sol.push_back('L');
            lst = vec.front();
            vec.pop_front();
            continue;
        }
        if(vec.front()<=lst){
            sol.push_back('R');
            lst = vec.back();
            vec.pop_back();
            continue;
        }
        if(vec.front()<vec.back()){
            sol.push_back('L');
            lst = vec.front();
            vec.pop_front();
        }else if(vec.back()<vec.front()){
            sol.push_back('R');
            lst = vec.back();
            vec.pop_back();
        }else{
            flag = true;
            break;
        }
    }
    if(!flag){
        cout<<sol.size()<<endl;
        for (int i = 0; i < sol.size(); ++i) {
            cout<<sol[i];
        }
        cout<<endl;
    }else{
        int cntFront = 1;
   //     cout<<vec.size()<<endl;
        for (int i = 1; i <vec.size() ; ++i) {
            if(vec[i]>vec[i-1]){
                cntFront++;
            }else{
                break;
            }
        }
        deque<int> backk = vec;
        reverse(backk.begin(),backk.end());
        int cntBack = 1;
        for (int i = 1; i <backk.size() ; ++i) {
            if(backk[i]>backk[i-1]){
                cntBack++;
            }else{
                break;
            }
        }
      //  cout<<sol.size()<<endl;
    //    cout<<cntFront<<" "<<cntBack<<endl;
        if(cntFront>cntBack){
            for (int i = 0; i < cntFront; ++i) {
                sol.push_back('L');
            }
        }else{
            for (int i = 0; i < cntBack; ++i) {
                sol.push_back('R');
            }
        }
        cout<<sol.size()<<endl;
        for (int i = 0; i < sol.size(); ++i) {
            cout<<sol[i];
        }
        cout<<endl;
    }
}