#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
const int N = 50002;
const int INF = 100000;
struct node {
    int to, w, next;
};
node edge[N * 3];
int n, num, maxb, dist[N], adj[N];
bool visit[N];
void spfa() {
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    int i, u, v, c;
    queue<int> q;

    for(i = 0; i <= maxb; i++) {
        q.push(i); //将所有的顶点入队列
        visit[i] = true;
    }

    while(!q.empty()) {
        u = q.front();
        q.pop();
        visit[u] = false;

        for(i = adj[u]; i != -1; i = edge[i].next) {
            v = edge[i].to;
            c = edge[i].w;

            if(dist[u] + c > dist[v]) {
                dist[v] = dist[u] + c;

                if(!visit[v]) {
                    //    cout<<v<<endl;
                    q.push(v);
                    visit[v] = true;
                }
            }
        }
    }

    printf("%d\n", dist[maxb] - dist[0]);
}
int main() {
    int i, u, v, c;
    scanf("%d", &n);
    num = 0;
    maxb = -INF;
    memset(adj, -1, sizeof(adj));
    node tmp;

    for(i = 0; i < n; i++) {
        scanf("%d%d%d", &u, &v, &c);
        maxb = (maxb < (v + 1)) ? (v + 1) : maxb;
        tmp.to = v + 1;
        tmp.w = c;
        tmp.next = adj[u];
        edge[num] = tmp;
        adj[u] = num++;
    }

    for(i = 0; i < maxb; i++) {
        tmp.to = i + 1;
        tmp.w = 0;
        tmp.next = adj[i];
        edge[num] = tmp;
        adj[i] = num++;

        tmp.to = i;
        tmp.w = -1;
        tmp.next = adj[i + 1];
        edge[num] = tmp;
        adj[i + 1] = num++;
    }

    spfa();
    return 0;
}
