#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=1;i<n*2;i++){
        int space,star;
        if(i<=n){
            space=n-i;
            star=i*2-1;
        }
        else{
            space=i-n;
            star=4*n-1-2*i;
        }
        for(int j=0;j<space;j++){
            cout << " ";
        }
        for(int j=0;j<star;j++){
            cout << "*";
        }
        cout<<endl;
    }
    return 0;
}
