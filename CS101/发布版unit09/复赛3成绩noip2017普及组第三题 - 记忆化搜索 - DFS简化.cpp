#include<iostream>
#include<algorithm>
#define INF 100000
#define M 105	//棋盘大小 
using namespace std;
int d[M][M],f[M][M],m,n,x,y,z; //d为原颜色，f为费用 
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void go(int i,int j,int c,int e,bool magic){
	//位置(i,j)，颜色c，费用e，magic表示能否用魔法 
    if(i>m||i<1||j<1||j>m)return; //越界检测 
    f[i][j]=e;	//更新费用 
    for(int k=0;k<4;k++){//朝四个方向移动 
    	int a=i+dx[k],b=j+dy[k],ee=(c!=d[a][b]);
    	//(a,b)为移动后新位置，当颜色不同时ee费用为1
    	if(d[a][b]&&e+ee<f[a][b]) //d[a][b]有色 
			go(a,b,d[a][b],e+ee,1);
		if(!d[a][b]&&magic&&e+2<f[a][b])//d[a][b]无色 
			go(a,b,c,e+2,0);
	}	
}
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y>>z; d[x][y]=z+1;
    }
    fill(f[0],f[0]+M*M,INF);
    go(1,1,d[1][1],0,1);
    if(f[m][m]==INF)cout<<-1<<endl;
    else cout<<f[m][m]<<endl;
    return 0;
}
