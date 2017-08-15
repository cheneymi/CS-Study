#include <iostream>
using namespace std;

int main() {
    long long n;
    bool found3=false;
    bool found7=false;
    bool found2=false;
    bool found1=false;
    cin>>n;
    while (n!=0) {
        int digit=n%10;
        if(digit==3) found3=true;
        if(digit==7) found7=true;
        if(digit==2) found2=true;
        if(digit==1) found1=true;
        n=n/10;
    }
    if(found3&&found7&&found2&&found1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
