#include <iostream>
using namespace std;

int main() {
    int a,k;
    cin>>a>>k;
    int count=0;
    int b=a;
    while(a>0){
        if(a%10==3){
            count++;
        }
        a=a/10;
    }
    if(count==k&&b%19==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
