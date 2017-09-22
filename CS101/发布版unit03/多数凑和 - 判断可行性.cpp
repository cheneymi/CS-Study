#include <iostream>
#define N 100 
#define M 10
using namespace std;
int n,m,x[M],v[M];
bool f[M][N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i) cin>>x[i];
	f[0][0]=1;
	for (int i=1;i<=m;++i)  {
		f[i][0]=1;  
		for (int j=1;j<=n;++j) {  
			if (j<x[i])    
				f[i][j]=f[i-1][j];
			else 		
				f[i][j]=f[i-1][j] or f[i-1][j-x[i]];
			//¿ÉÒÔ¼òÐ´£ºf[i][j]=f[i-1][j] or (j<x[i] and f[i-1][j-x[i]]); 
		} 	
	} 
	if(f[m][n]) cout<<"Yes"<<endl;
	else cout<<"No"<<endl; 
	return 0;
} 
