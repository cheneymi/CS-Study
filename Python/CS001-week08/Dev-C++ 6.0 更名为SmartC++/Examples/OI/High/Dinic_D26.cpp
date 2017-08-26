#include <cstdio>
#include <cstring>
FILE *in,*out;
int n,tot=1,b[30001],a[1000000][3];
int main()
{
   in=fopen("beltline.in","r");
   out=fopen("beltline.out","w");
   void add(int,int,int);
   bool build();
   int dinic(int,int);
   int m;
   fscanf(in,"%d%d",&n,&m);
   for (int i=1;i<=n;i++)
      fscanf(in,"%*d%*d");
   for (int i=1;i<=m;i++)
   {
      int x,y,z;
      fscanf(in,"%d%d%d",&x,&y,&z);
      add(x,y,z);
   }
   int ans=0;
   while (build())
      ans+=dinic(1,1<<30);
   fprintf(out,"%d\n",ans);
   fclose(in),fclose(out);
   return(0);
}
void add(int x,int y,int v)
{
   a[++tot][0]=y,a[tot][1]=v,a[tot][2]=b[x],b[x]=tot;
   a[++tot][0]=x,a[tot][1]=v,a[tot][2]=b[y],b[y]=tot;
}
int d[30001],q[30001];
bool build()
{
   int l,r;
   memset(d,0,sizeof(d));
   l=r=d[1]=q[1]=1;
   while (l<=r)
   {
      int x=q[l];
      for (int i=b[x];i;i=a[i][2])
      {
         int y=a[i][0];
         if (d[y] || !a[i][1])
            continue;
         d[y]=d[x]+1;
         q[++r]=y;
         if (y==n)
            return(true);
      }
      l++;
   }
   return(false);
}
int dinic(int x,int flow)
{
   int min(int,int);
   if (x==n)
      return(flow);
   int k=flow;
   for (int i=b[x];i;i=a[i][2])
   {
      int y=a[i][0];
      if (d[y]!=d[x]+1 || !a[i][1])
         continue;
      int t=dinic(y,min(k,a[i][1]));
      k-=t;
      a[i][1]-=t;
      a[i^1][1]+=t;
      if (!k)
         return(flow);
   }
   if (k==flow)
      d[x]=-1;
   return(flow-k);
}
int min(int x,int y)
{
   return(x<y?x:y);
}

