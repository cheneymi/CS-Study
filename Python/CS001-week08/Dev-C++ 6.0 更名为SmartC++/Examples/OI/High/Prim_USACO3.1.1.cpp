/*
ID: mrw1
LANG: C++
TASK: agrinet
*/
# include <cstdio>
# include <cstdlib>
# include <cstring>
FILE *in, *out;
const int INF = 2147483647;
int n, ans = 0;
int map[103][103];
int dist[103];
void Prim(int v0)
{
	int i, j, k, mindis;
	bool done[103] = {false};
	memset(dist, 44, sizeof(dist));
	dist[v0] = 0;
	for(i = 1; i <= n; i++ )
	{
		mindis = INF;
		for(j = 1; j <= n; j++ )
			if( !done[j] && dist[j] < mindis ) k = j, mindis = dist[j];
		ans += dist[k];
		done[k] = true;
		dist[k] = 0;
		for(j = 1; j <= n; j++ )
			if( dist[j] > map[k][j] )
				dist[j] = map[k][j];
	}
}
int main()
{
	int i, j;
	in = fopen("agrinet.in","r");
	out = fopen("agrinet.out","w");
	fscanf(in,"%d", &n);
	for(i = 1; i <= n; i++ )
		for(j = 1; j <= n; j++ )
			fscanf(in,"%d", &map[i][j]);
	Prim(1);
	fprintf(out,"%d\n", ans);
	return 0;
}
