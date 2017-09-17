#include <iostream>
#define MAXN 501
#define MAXC 1001
using namespace std;

int main() {
    int C,n;
    cin>>C>>n;
    int w[MAXN],v[MAXN],f[MAXN][MAXC];
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for (int i=1; i<=n; i++){
        for (int j=0; j<=C; j++) {
            if (j<w[i])
                f[i][j]=f[i-1][j];
            else
                f[i][j]=max(f[i-1][j], f[i-1][j - w[i]] + v[i]);
        }
    }
    cout<<f[n][C]<<endl;
    return 0;
}
