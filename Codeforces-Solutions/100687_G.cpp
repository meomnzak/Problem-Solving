#include <iostream>


using namespace std;

int main(){
    bool flag = false;
    bool visited[10] = {false};
    int temp;
    int num1;
    int num2;
    cin>>num1;
    cin>>num2;
    for(int i = num1 ; i<=num2 ; i++){
        temp = i;
        bool visited[10] = {false};
        while(temp){
            if(visited[temp%10]){
                break;
            }
            visited[temp%10] = true;
            temp/=10;
        }
        if(temp==0){
            cout<<i<<endl;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }
    return 0;
}