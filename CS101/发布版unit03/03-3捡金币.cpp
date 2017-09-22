#include <iostream>
#define N 30 
#define M 30
using namespace std;
int n,m,i,j,f[M][N],d[M][N];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) {
		char x;
		cin>>x; 
		d[i][j]=x-'0';
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			f[i][j]=max(f[i-1][j],f[i][j-1])+d[i][j];
	cout<<f[n][m]<<endl; 
	return 0;
} 
