#include <iostream>
#define M 501 
#define N 2001
using namespace std;
int n,m,w[M],v[M],f[M][N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i) cin>>w[i];		
	for (int i=1; i<=m; ++i)   //循环查看物品i 
		for (int j=0; j<=n; ++j) {  //循环查看背包剩余重量j 
			if (j<w[i])   // 物品i太重，无法放入 
				f[i][j]=f[i-1][j];
			else 		// 比较两种决策：物品i可以放，或者不放
				f[i][j]=max(f[i-1][j], f[i-1][j - w[i]] + w[i]);
		} 
	cout<<f[m][n]<<endl; 
	return 0;
} 
