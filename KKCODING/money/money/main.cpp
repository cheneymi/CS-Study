#include <iostream>
using namespace std;

int main() {
    int k=1,money=0;
    double n;
    cin>>n;
    while(money<n){
        money+=k;
        k+=1;
    }
    cout<<k-1<<endl;
    return 0;
}