#include <iostream>
#define N 10 
#define M 10
using namespace std;
int n,m,i,j;
char d[M][N];
bool f[M][N]; 
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
				f[i][j]=f[i-1][j] or f[i][j-1];
		}
	if(f[n][m]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl; 
	return 0;
} 
