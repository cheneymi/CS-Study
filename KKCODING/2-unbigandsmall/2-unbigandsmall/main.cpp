#include <iostream>
using namespace std;

int findmax(int data[],int n){
    int max;
    max=data[0];
    for(int i=1;i<n;i++){
        if(data[i]>max){
            max=data[i];
        }
    }
    return max;
}

int findmin(int data[],int n){
    int min;
    min=data[0];
    for(int i=1;i<n;i++){
        if(data[i]<min){
            min=data[i];
        }
    }
    return min;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int max=findmax(a,n);
    int min=findmin(a,n);
    for(int i=0;i<n;i++){
        if(a[i]!=max&&a[i]!=min){
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
