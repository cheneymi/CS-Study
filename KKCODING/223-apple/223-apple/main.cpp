#include <iostream>
using namespace std;

int main() {
    int n,x,y;
    cin>>n>>x>>y;
    n-=y/x;
    if(y%x>0) n-=1;
    if(n<0) n=0;
    cout<<n<<endl;
    return 0;
}
