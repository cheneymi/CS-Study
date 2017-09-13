#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    long long a[n+1][m+1];
    for(int j=1;j<=m;j++)
        a[1][j]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=0;
            for(int k=1;k<=j;k++){
                a[i][j]+=a[i-1][k];
            }
        }
    }
    cout<<a[n][m]<<endl;
    return 0;
}
