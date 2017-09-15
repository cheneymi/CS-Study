#include <iostream>
#define maxn 1001
using namespace std;

int main() {

    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='?'){
                int count=0;
                if(a[i-1][j]=='*'&&i-1>=0){
                    count++;
                }
                if(a[i-1][j-1]=='*'&&i-1>=0&&j-1>=0){
                    count++;
                }
                if(a[i-1][j+1]=='*'&&i-1>=0&&j+1<=m-1){
                    count++;
                }
                if(a[i][j-1]=='*'&&j-1>=0){
                    count++;
                }
                if(a[i+1][j]=='*'&&i+1<=n-1){
                    count++;
                }
                if(a[i+1][j-1]=='*'&&i+1<=n-1&&j-1>=0){
                    count++;
                }
                if(a[i+1][j+1]=='*'&&i+1<=n-1&&j+1<=m-1){
                    count++;
                }
                if(a[i][j+1]=='*'&&j+1<=m-1){
                    count++;
                }
                cout<<count;
            }
            else
                cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}
