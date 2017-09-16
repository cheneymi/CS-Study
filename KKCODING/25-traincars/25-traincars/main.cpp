#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    int top=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int index;
    for(int i=0;i<n;i++){
        if(a[i]!=index+1){
            top++;
            c[top]=a[i];
        }
        else{
            b[index]=a[i];
            index++;
        }
        while(top>0&&c[top]==index+1){
            b[index]=c[top];
            top--;
            index++;
        }
    }
    if(top>0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
    return 0;
}
