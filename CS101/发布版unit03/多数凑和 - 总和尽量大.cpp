#include <iostream>
#define N 100 
#define M 10
using namespace std;
int n,m,x[M],v[M],f[M][N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i) cin>>x[i];
	for (int i=1;i<=m;++i)   
		for (int j=0;j<=n;++j) {  
			if (j<x[i])    
				f[i][j]=f[i-1][j];
			else 		
				f[i][j]=max(f[i-1][j],f[i-1][j-x[i]]+x[i]);
		} 
	cout<<f[m][n]<<endl; 
	return 0;
} 
