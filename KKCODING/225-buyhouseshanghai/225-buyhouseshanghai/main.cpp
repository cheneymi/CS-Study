#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n,x,m;//n,x,m
    int months=0;//months
    cin>>n>>x>>m;//enter
    while(x<n){
        if(m<=(n*0.01)){
            cout<<"Mission Impossible";
            return 0;
        }
        n=n+n*0.01;
        x=x+m;
        months++;
    }
    cout<<months<<endl;//output
    return 0;//return
}
