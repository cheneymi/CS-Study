#include<iostream>
#define M 100001
using namespace std;
int f[M],n,a,b,c,xa,xb,xc,i,j;
int main(){
	cin>>n>>a>>b>>c;
	f[0]=0;
	for(i=1;i<=n;i++){
		xa=xb=xc=0;
		if(i>=a) xa=f[i-a]+a;
		if(i>=b) xb=f[i-b]+b;
		if(i>=c) xc=f[i-c]+c;
		f[i]=max(max(xa,xb),xc);
	}
	cout<<f[n]<<endl;	
	return 0;
}
