#include <iostream>
using namespace std;
int main() {
    int n,m,max=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<=n-m;i++){
        int tmp=0;
        for(int j=i;j<i+m;j++){
            tmp+=a[j];
        }
        if(tmp>max) max=tmp;
    }
    cout<<max<<endl;
    return 0;
}
