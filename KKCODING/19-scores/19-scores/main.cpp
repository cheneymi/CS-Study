#include <iostream>
using namespace std;

int main() {
    string a[101];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=100;i++){
        a[i]="NO";
    }
    for(int i=0;i<n;i++){
        string sn;
        float score;
        cin>>sn>>score;
        a[score]=sn;
    }
    int count;
    for(int i=100;i>0;i--){
        if(a[i]!="NO"){
            count++;
        }
        if(count==k){
            cout<<a[i]<<" "<<i;
            break;
        }
    }
    cout <<endl;
    return 0;
}
