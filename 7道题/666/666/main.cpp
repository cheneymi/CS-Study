#include <iostream>
using namespace std;

int main() {
    long long n;
    cin>>n;
    int six=0;
    while (n!=0) {
        int digit=n%10;
        if(digit==6)
            six+=1;
        n=n/10;
    }
    if(six!=0){
        for(int i=0;i<six;i++)
            cout<<6;
    }
    else
        cout<<"Unhappy";
    cout<<endl;
    return 0;
}
