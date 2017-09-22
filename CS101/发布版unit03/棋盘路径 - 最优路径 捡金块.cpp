#include <iostream>
#define N 10 
#define M 10
using namespace std;
int n,m,i,j,f[M][N];
char d[M][N];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++) 
		for(j=1;j<=m;j++) 
			cin>>d[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(d[i][j]=='$') f[i][j]++;
		}
	cout<<f[n][m]<<endl; 
	return 0;
} 
