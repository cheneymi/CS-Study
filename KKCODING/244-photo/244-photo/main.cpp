#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long f[n+1];
    f[0]=1;
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]*(4*i-2)/(i+1);
    }
    cout<<f[n]<<endl;
    return 0;
}
