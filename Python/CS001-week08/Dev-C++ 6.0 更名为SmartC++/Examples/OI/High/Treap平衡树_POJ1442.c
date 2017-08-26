#include <stdio.h>
long m,n;
long a[30010];
long fa[30010],left[30010],right[30010],data[30010],key[30010],size[30010];
long tot=0,root;
void Init()
{
     long i;
     scanf("%ld%ld",&m,&n);
     for(i=1;i<=m;i++) scanf("%ld",&a[i]);
}
void Rotate(long x)
{
     long y,z;
     y=fa[x];
     z=fa[y];
     fa[x]=z;
     fa[y]=x;
     if(x==left[y])
     {
        fa[right[x]]=y;
        left[y]=right[x];
        right[x]=y;
     }
     else
     {
        fa[left[x]]=y;
        right[y]=left[x];
        left[x]=y;
     }
     if(y==left[z]) left[z]=x;else right[z]=x;
     size[y]=size[left[y]]+size[right[y]]+1;
     size[x]=size[left[x]]+size[right[x]]+1;
     if(y==root) root=x;
}
void Insert(long x)
{
     long p,q;
     if(tot==0)
     {
        tot++;
        root=tot;
        fa[tot]=left[tot]=right[tot]=0;
        data[tot]=x;
        key[tot]=rand()+rand()+rand();
        size[tot]=1;
        return;
     }
     p=root;
     while(1)
     {
        q=p;
        size[q]++;
        if(data[q]<=x) p=right[q];else p=left[q];
        if(p==0) break;
     }
     tot++;
     fa[tot]=q;
     left[tot]=right[tot]=0;
     data[tot]=x;
     size[tot]=1;
     key[tot]=rand()+rand()+rand();
     if(data[q]<=x) right[q]=tot;else left[q]=tot;
     p=tot;
     while(key[p]>key[fa[p]]) Rotate(p);
}     
long Find(long x)
{
     long p=root;
     while(1)
     {
        if(size[left[p]]+1==x) return data[p];
        if(size[left[p]]+1<x)
        {
           x=x-size[left[p]]-1;
           p=right[p];
        }
        else p=left[p];
     }
}
void Work()
{
     long i,j,x,now=0;
     key[0]=2147483647;
     for(i=1;i<=n;i++)
     {
        scanf("%ld",&x);
        for(j=now+1;j<=x;j++) Insert(a[j]);
        now=x;
        printf("%ld\n",Find(i));
     }
}
int main()
{
    Init();
    Work();
    return 0;
}
