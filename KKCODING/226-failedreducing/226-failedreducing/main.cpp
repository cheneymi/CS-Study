#include <iostream>
using namespace std;
int main() {
    int n,max=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<=n-7;i++){
        int tmp=0;
        for(int j=i;j<i+7;j++){
            tmp+=a[j];
        }
        if(tmp>max) max=tmp;
    }
    cout<<max<<endl;
    return 0;
}
