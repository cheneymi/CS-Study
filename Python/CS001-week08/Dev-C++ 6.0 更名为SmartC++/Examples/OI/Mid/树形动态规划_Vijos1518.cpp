#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int lson[110], rson[110], num[110];
int n, m;
int w[110], d[110], fa[110];
int f[110][60][110], dis[110];
inline void dfs(int x) {
    dis[x] = d[x] + dis[fa[x]];

    if(lson[x] != -1) dfs(lson[x]);

    if(rson[x] != -1) dfs(rson[x]);
}
inline int dp(int x, int y, int z) {
    if(f[x][y][z] != -1) return f[x][y][z];

    f[x][y][z] = 0x3f3f3f3f;
    int t;

    for(int j = 0; j <= y; j++) {
        t = (dis[x] - dis[z]) * w[x];

        if(lson[x] != -1) t += dp(lson[x], j, z);

        if(rson[x] != -1) t += dp(rson[x], y - j, z);

        f[x][y][z] = min(f[x][y][z], t);

        if(j < y) {
            t = 0;

            if(lson[x] != -1) t += dp(lson[x], j, x);

            if(rson[x] != -1) t += dp(rson[x], y - j - 1, z);

            f[x][y][z] = min(f[x][y][z], t);
        }
    }

    return f[x][y][z];
}
int main() {
    scanf("%d%d", &n, &m);
    memset(num, -1, sizeof num);
    memset(lson, -1, sizeof lson);
    memset(rson, -1, sizeof rson);
    memset(f, -1, sizeof f);

    for(int i = 1, v; i <= n; i++) {
        scanf("%d%d%d", &w[i], &v, &d[i]);

        if(num[v] == -1) lson[v] = i;
        else rson[num[v]] = i;

        num[v] = i;
        fa[i] = v;
    }

    dfs(0);
    printf("%d\n", dp(0, m, 0));
    return 0;
}
