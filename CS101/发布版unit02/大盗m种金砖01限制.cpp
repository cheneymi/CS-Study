#include <iostream>
#define M 501 
#define N 2001
using namespace std;
int n,m,w[M],v[M],f[M][N]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i) cin>>w[i];		
	for (int i=1; i<=m; ++i)   //ѭ���鿴��Ʒi 
		for (int j=0; j<=n; ++j) {  //ѭ���鿴����ʣ������j 
			if (j<w[i])   // ��Ʒi̫�أ��޷����� 
				f[i][j]=f[i-1][j];
			else 		// �Ƚ����־��ߣ���Ʒi���Էţ����߲���
				f[i][j]=max(f[i-1][j], f[i-1][j - w[i]] + w[i]);
		} 
	cout<<f[m][n]<<endl; 
	return 0;
} 
