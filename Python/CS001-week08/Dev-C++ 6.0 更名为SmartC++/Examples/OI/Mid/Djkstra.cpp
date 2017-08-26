
/*
注意----------
map与dist的初始值必须为oo
起始点的dist值为0
访问过的点不再访问
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define maxn 1001
# define oo 1147483647

int N,M;
int dist[maxn];
int map[maxn][maxn];
bool f[maxn] = {false};

int Dijkstra(int a, int b )
{
	int i,j,k;
	for(int i = 0; i <= N; i++ )dist[i] = oo;
	dist[a] = 0;
	for(int i = 1; i <= N; i++ )
	{
		k = 0;
		for(j = 1; j <= N; j++ )
			if( !f[j] && dist[j] < dist[k] ) k = j;
		f[k] = true;
		for(j = 1; j <= N; j++ )
			if( map[k][j] + dist[k] < dist[j] ) dist[j] = map[k][j] + dist[k];

	}
	for(int i = 1; i <= N; i++ )
		printf("%d ",dist[i]);	
}

int main()
{
	int a,b,c;
	scanf( "%d%d", &N, &M);
	for(int i = 1; i <= N; i++ )
		for(int j = 1; j <= N; j++ )
			map[i][j] = oo;
	for(int i = 1; i <= M; i++ )
	{
		scanf( "%d%d%d", &a, &b, &c );
		map[a][b] = c;
	}
	Dijkstra(1,N);
	return 0;
}
