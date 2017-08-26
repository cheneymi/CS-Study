/*
relax是标记释放

mk是标记
这题是 01串 修改是[L,R]取反 ，询问是有多少个1吧。。

*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define rep(x,n) for (int x=1;x<=n;x++)
#define Maxn 400005
using namespace std;
struct Node
{
    int s,e;
    bool mk;
    void make() {e=s-e; mk^=1;}
}t[Maxn];
int h,m,n,q;

void Init()
{
    scanf("%d%d",&n,&q);
    for (;(n+1)>>h;h++); m=1<<h;
    rep(i,n) t[i+m].s=1;
    for (int i=m-1;i;i--) t[i].s=t[i+i].s+t[i+i+1].s;
}

inline void Relax(int x)
{
    int p;
    for (int i=h;i;i--) if (t[x>>i].mk)
    {
        p=x>>i; t[p].mk=0;
        t[p+p].make(); t[p+p+1].make();
    }
}

inline void chg(int l,int r)
{
    l+=m-1; r+=m+1; int ll=l>>1,rr=r>>1;
    Relax(l); Relax(r);
    for (;l!=r-1;l>>=1,r>>=1)
    {
        if ((l&1)==0) t[l+1].make();
        if ((r&1)==1) t[r-1].make();
    }
    for (;ll;ll>>=1,rr>>=1)
    {
        t[ll].e=t[ll+ll].e+t[ll+ll+1].e;
        if (rr!=ll) t[rr].e=t[rr+rr].e+t[rr+rr+1].e;
    }
}

inline void ask(int l,int r)
{
    l+=m-1; r+=m+1; int s=0;
    Relax(l); Relax(r);
    for (;l!=r-1;l>>=1,r>>=1)
    {
        if ((l&1)==0) s+=t[l+1].e;
        if ((r&1)==1) s+=t[r-1].e;
    }
    printf("%d\n",s);
}

void Work()
{
    int x,y,z;
    rep(i,q)
    {
        scanf("%d%d%d",&x,&y,&z);
        if (!x) chg(y,z);
        else ask(y,z);
    }
}

int main()
{
    Init();
    Work();
    return 0;
}
