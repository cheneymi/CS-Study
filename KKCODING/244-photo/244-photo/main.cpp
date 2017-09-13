#include <iostream>
#define M 35
using namespace std;

long long n,f[M]={1};

void ges(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            f[j]=f[j-1]+f[j];
    cout<<f[n]<<endl;
}

void catalan(){
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]*(4*i-2)/(i+1);
    cout<<f[n]<<endl;
}

int main() {
    ges();
    //catalan();
    return 0;
}

