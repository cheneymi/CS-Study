#include <iostream>
#define maxn 2001
#define maxm 501
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int f[maxn],x[maxm];
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    f[0]=0;
    for(int i=1;i<=n;i++){
        int tmp=f[i-1];
        for(int j=1;j<=m;j++){
            if(tmp<f[i-x[j]]+x[j]&&x[j]<=i){
                tmp=f[i-x[j]]+x[j];
            }
        }
        f[i]=tmp;
    }
    cout<<f[n]<<endl;
    return 0;
}
