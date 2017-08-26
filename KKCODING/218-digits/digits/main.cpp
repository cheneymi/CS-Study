#include <iostream>
using namespace std;

int main() {
    long long n;
    cin>>n;
    int digits=0;
    while (n!=0) {
        digits+=1;
        n=n/10;
    }
    if(digits==0)
        digits+=1;
    cout<<digits<<endl;
    return 0;
}
