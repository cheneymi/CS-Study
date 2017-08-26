#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int father[50002], a, b, m, n, p;
int find(int x) {
    if(father[x] != x) father[x] = find(father[x]);

    return father[x];
}
int main() {
    scanf("%d%d%d", &n, &m, &p);

    for(int i = 1; i <= n; i++)father[i] = i;

    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        father[a] = b;
    }

    for(int i = 1; i <= p; i++) {
        scanf("%d%d", &a, &b);
        a = find(a);
        b = find(b);

        if(a == b)printf("Yes");
        else printf("No");
    }

    return 0;
}
