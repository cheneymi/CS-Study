#include<iostream>
#define V 20005
#define N 50
using namespace std;
bool f[N][V];
int v,n,i,j,w[N];
int main(){
	cin>>v>>n;
	for(i=1;i<=n;i++) cin>>w[i];
	f[0][0]=1;
	for(i=1;i<=n;i++){
		f[i][0]=1;
		for(j=1;j<=v;j++) {
			if(j>=w[i]) f[i][j]=f[i-1][j] or f[i-1][j-w[i]];
			else f[i][j]=f[i-1][j]; 
		}			
	}
	for(j=v;j>=0 && !f[n][j];j--);
	cout<<v-j<<endl;
	return 0;
}
