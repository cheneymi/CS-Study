#include<iostream>
#define M 100001
using namespace std;
int f[M],n,a,b,c,xa,xb,xc,i,j,tmp;

int main(){
    cin>>n>>a>>b>>c;
    f[0]=0;
    for(i=1;i<=n;i++){
        if(i>=a) xa=f[i-a]+a;
        else xa=0;
        if(i>=b) xb=f[i-b]+b;
        else xb=0;
        if(i>=c) xc=f[i-c]+c;
        else xc=0;
        tmp=max(xa,xb);
        tmp=max(tmp,xc);
        f[i]=tmp;
    }
    cout<<f[n]<<endl;	
    return 0;
}
