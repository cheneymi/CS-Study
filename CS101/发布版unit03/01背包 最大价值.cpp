#include <iostream>
#define N 100 
#define M 10
using namespace std;
int n,m,w[M],v[M],f[M][N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<= m;++i) cin>>w[i]>>v[i];		
	// 计算f[i][j]从前i件物品中选出总重量不超过j的物品的最大价值 
	for (int i=1; i<=m; ++i)   //循环查看物品i 
		for (int j=0; j<=n; ++j) {  //循环查看背包剩余重量j 
			if (j<w[i])   // 物品i太重，无法放入 
				f[i][j]=f[i-1][j];
			else 		// 比较两种决策：物品i可以放，或者不放
				f[i][j]=max(f[i-1][j], f[i-1][j - w[i]] + v[i]);
		} 
	cout<<f[m][n]<<endl; 
	return 0;
} 
