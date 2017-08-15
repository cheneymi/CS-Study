#include <iostream>
using namespace std;

int main() {
    int n,times=0;
    cin>>n;
    while (n>0) {
        times+=1;
        n-=2;
        if(times%3==0){
            n-=10;
        }
    }
    cout<<times<<endl;
    return 0;
}
