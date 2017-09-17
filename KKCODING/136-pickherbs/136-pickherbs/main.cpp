#include <iostream>
#define MAXT 1001
#define MAXM 101
using namespace std;

int main() {
    int T,M;
    cin>>T>>M;
    int w[MAXM],v[MAXM],f[MAXM][MAXT];
    for(int i=1;i<=M;i++){
        cin>>w[i]>>v[i];
    }
    for (int i=1; i<=M; i++){
        for (int j=0; j<=T; j++) {
            if (j<w[i])
                f[i][j]=f[i-1][j];
            else
                f[i][j]=max(f[i-1][j], f[i-1][j - w[i]] + v[i]);
        }
    }
    cout<<f[M][T]<<endl;
    return 0;
}
