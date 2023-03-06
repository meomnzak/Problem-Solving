#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
typedef long long ll;


vector<int> vec;

map<int,int> mp;
int n;

bool can(int gap){
    priority_queue<int> pq;
    for (int i = 0; i < vec.size(); ++i) {
        pq.push(vec[i]);
    }
    int time = 0;
    deque<pair<int,int>> hold;
    while (pq.size()>0){
        int go = pq.top();
        pq.pop();
        if(go-1>0){
            hold.push_back({time+gap+1,go-1});
        }
        time++;
        if(hold.size()>0){
            if(hold.front().first==time){
                pq.push(hold.front().second);
                hold.pop_front();
            }
        }
    }
    return (pq.size()==0)&&(hold.size()==0);
}


int binarySearch(int low , int high){
    int res = -1;
    while(low<=high){
        int mid = low+ (high-low)/2;
        if(can(mid)){
            low = mid+1;
            res = mid;
        }else{
            high = mid-1;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        mp.clear();
        int num;
        for (int i = 0; i < n; ++i) {
            cin>>num;
            mp[num]++;
        }
        vec.clear();
        for (auto it = mp.begin() ; it!=mp.end() ; it++) {
            vec.push_back(it->second);
        }

        cout<<binarySearch(0,n)<<endl;

    }
}