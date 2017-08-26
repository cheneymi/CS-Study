#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxnode 1000
FILE *fin = stdin;
FILE *fout = stdout;
struct node { //邻接表
    int v, p;
    node *next;
    node() {
        next = NULL;
    }
    node(int po, int va, node *li) {
        v = va;
        p = po;
        next = li;
    }
}*G[maxnode];
int N, M;

struct queue { //队列
    int a[10000], head, tail;
    queue() {
        head = -1, tail = -1;
    }
    void push(int x) {
        a[++head] = x;
    }
    int pop() {
        return a[++tail];
    }
    bool isempty() {
        return head == tail;
    }
} que;

void init() { //读图
    int a, b, v;
    fscanf(fin, "%d%d", &N, &M);

    for(int i = 1; i <= N; i++)
        G[i] = new node;

    for(int i = 1; i <= M; i++) {
        fscanf(fin, "%d%d%d", &a, &b, &v);
        node *p = new node(b, v, G[a]->next);
        G[a]->next = p;
        p = new node(a, v, G[b]->next);
        G[b]->next = p;
    }
}

int dist[maxnode];
bool in[maxnode];
bool relax(int u, int v, int dis) {
    if(dist[v] == -1) return 0;

    if(dist[u] > dist[v] + dis || dist[u] == -1) {
        dist[u] = dist[v] + dis;
        return 1;
    }

    return 0;
}

void SPFA(int s) { //源--S

    memset(dist, -1, sizeof(dist));
    int now;
    node *p;
    dist[s] = 0;
    in[s] = 1;
    que.push(s);

    while(!que.isempty()) {
        now = que.pop();
        in[now] = 0;
        p = G[now]->next;

        while(p) {
            if(relax(p->p, now, p->v))
                if(!in[p->p]) {
                    in[p->p] = 1;
                    que.push(p->p);
                }

            p = p->next;
        }
    }
}

int main() {
    init();
    SPFA(1);

    for(int i = 1; i <= N; i++)
        fprintf(fout, "%d ", dist[i]);

    return 0;
}
