#include <stdio.h>
long fa[1000010],left[1000010],right[1000010],data[1000010],num[1000010],key[1000010];
long tot,all,root;
void Rotate(long x)
{
     long y,z;
     y=fa[x];
     z=fa[y];
     fa[x]=z;
     fa[y]=x;
     if(x==left[y])
     {
        left[y]=right[x];
        fa[right[x]]=y;
        right[x]=y;
     }
     else
     {
        right[y]=left[x];
        fa[left[x]]=y;
        left[x]=y;
     }
     if(y==left[z]) left[z]=x;else right[z]=x;
     if(root==y) root=x;
}
void Insert(long x,long y)
{
     long p,q;
     tot++;
     all++;
     if(tot==1)
     {
        root=all;
        fa[all]=left[all]=right[all]=0;
        data[all]=y;
        num[all]=x;
        key[all]=rand()+rand()+rand();
        return;
     }
     p=root;
     while(1)
     {
        q=p;
        if(data[q]<y) p=right[q];else p=left[q];
        if(p==0) break;
     }
     fa[all]=q;
     left[all]=right[all]=0;
     data[all]=y;
     num[all]=x;
     key[all]=rand()+rand()+rand();
     if(y<data[q]) left[q]=all;else right[q]=all;
     p=all;
     while(key[p]>key[fa[p]]) Rotate(p);
}
long Min()
{
     long p;
     if(tot==0) return 0;
     p=root;
     while(left[p]!=0) p=left[p];
     if(p==root)
     {
        root=right[p];
        fa[right[p]]=0;
     }
     else
     {
        left[fa[p]]=right[p];
        fa[right[p]]=fa[p];
     }
     tot--;
     return num[p];
}
long Max()
{
     long p;
     if(tot==0) return 0;
     p=root;
     while(right[p]!=0) p=right[p];
     if(p==root)
     {
        root=left[p];
        fa[left[p]]=0;
     }
     else
     {
        right[fa[p]]=left[p];
        fa[left[p]]=fa[p];
     }
     tot--;
     return num[p];
}       
void Work()
{
     long c,x,y;
     key[0]=2147483647;
     while(1)
     {
        scanf("%ld",&c);
        if(c==0) return;
        if(c==2) printf("%ld\n",Max());else
        if(c==3) printf("%ld\n",Min());
        else
        {
           scanf("%ld%ld",&x,&y);
           Insert(x,y);
        }
     }
}
int main()
{
    Work();
    return 0;
}

