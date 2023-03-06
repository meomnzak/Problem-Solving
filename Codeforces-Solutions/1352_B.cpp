#include <bits/stdc++.h>


using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
       long long sum = 0;
        bool flag = true;
        long long n,k;
        cin>>n>>k;
        vector<long long> vec;
            if(k==1){
                vec.push_back(n);
                cout<<"YES"<<endl;
                for(long long i = 0 ; i<vec.size() ; i++){
                            cout<<vec[i];
                            if(i!=vec.size()-1){
                                cout<<" ";
                            }
            }
                cout<<endl;
            }else{
                for(long long i = 0 ; i<k-1 ; i++){
                    vec.push_back(1);
                    sum++;
                }
                if((n-sum)<=0 || (n-sum)%2==0){
                    flag = false;
                }else{
                    vec.push_back(n-sum);
                }
                if(!flag){
                    bool flag2 = true;
                    vec.clear();
                    sum = 0;
                     for(long long i = 0 ; i<k-1 ; i++){
                        vec.push_back(2);
                        sum+=2;
                    }
                    if((n-sum)<=0 || (n-sum)%2==1){
                        flag2 = false;
                    }else{
                        vec.push_back(n-sum);
                    }
                    if(!flag2){
                         cout<<"NO"<<endl;
                    }else{
                        cout<<"YES"<<endl;
                        for(long long i = 0 ; i<vec.size() ; i++){
                            cout<<vec[i];
                            if(i!=vec.size()-1){
                                cout<<" ";
                            }
                        }
                        cout<<endl;
                    }
                   
                }else{
                    cout<<"YES"<<endl;
                    for(long long i = 0 ; i<vec.size() ; i++){
                        cout<<vec[i];
                        if(i!=vec.size()-1){
                            cout<<" ";
                        }
                    }
                    cout<<endl;
                }
            }
            
    }
    return 0;
}