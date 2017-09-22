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
			if(i==1 and j==1) f[i][j]=1;
			else if(d[i][j]=='#')
				f[i][j]=0;
			else
				f[i][j]=f[i-1][j]+f[i][j-1];
		}
	cout<<f[n][m]<<endl; 
	return 0;
} 
