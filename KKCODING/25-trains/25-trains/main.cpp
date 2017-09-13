#include <iostream>
using namespace std;
#define MAXN 10001

int main() {
    int n,top=0,index=1;
    int b[MAXN],c[MAXN];
    string ans="YES";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        top++;
        c[top]=i;
        while (top>0&&c[top]==b[index]) {
            b[index]=c[top];
            top--;
            index++;
        }
    }
    if(top>0) ans="NO";
    cout<<ans<<endl;
    return 0;
}
