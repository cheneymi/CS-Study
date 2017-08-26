# include <cstdio>
# include <cstdlib>

const int maxn = 10003;
int n, m;
int wa[maxn], wb[maxn], wv[maxn], ws[maxn];
int r[maxn], sa[maxn];
int cmp(int *r, int a, int b, int l)
{ return r[a] == r[b] && r[a+l] == r[b+l]; }

void da(int *r, int *sa, int n, int m)
{
	int i, j, p, *x = wa, *y = wb, *t;
	for (i = 0; i < m; ++i ) ws[i] = 0;
	for (i = 0; i < n; ++i ) ws[x[i] = r[i]]++;
	for (i = 1; i < m; ++i ) ws[i] += ws[i-1];
	for (i = n-1; i >= 0; --i ) sa[--ws[x[i]]] = i;
	for (j = 1, p = 1; p < n; j*=2, m = p)
	{
		for (p = 0,i = n-j; i < n; ++i ) y[p++] = i; //注意p = 0 
		for (i = 0; i < n; ++i ) if ( sa[i] >= j ) y[p++] = sa[i] - j;
		for (i = 0; i < n; ++i ) wv[i] = x[y[i]];
		for (i = 0; i < m; ++i ) ws[i] = 0;
		for (i = 0; i < n; ++i ) ws[wv[i]]++;
		for (i = 1; i < m; ++i ) ws[i] += ws[i-1];
		for (i = n-1; i >= 0; --i ) sa[--ws[wv[i]]] = y[i]; //注意和x[i]类比，此时x[i] = x[y[i]], 既最后为y[i] 
		t = x; x = y; y = t;
		for (p = 1, x[sa[0]] = 0, i = 1; i < n; ++i )
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1: p++; //注意传的是y 
	}
	return ;
}
int rank[maxn], height[maxn];
void calheight(int *r, int *sa, int n)
{
	int i, j, k = 0;
	for (i = 1; i <= n; ++i ) rank[sa[i]] = i;
	for (i = 0; i < n; height[rank[i++]] = k)
		for (k?k--:0, j = sa[rank[i]-1];r[i+k]==r[j+k];++k);
	return ;
}

char tmp[maxn];

int main()
{
	int i;
	scanf ("%s", tmp);
	n = strlen(tmp);
	tmp[n] = 0; m = 0;
	tmp[n+1] = '\0';
	for (i = 0; i < n+1; ++i ) r[i] = tmp[i], m = m < tmp[i] ? tmp[i]: m;
	da(r, sa, n+1, m+1);
	calheight(r, sa, n);
	for (i = 0; i < n+1; ++i ) printf("sa[%d] = %d\n", i, sa[i]);
	for (i = 0; i < n+1; ++i ) printf("rank[%d] = %d\n", i, rank[i]);
	for (i = 1; i < n+1; ++i ) printf("height[%d] = %d\n", i, height[i]);
	return 0;
}
