#include <iostream>
using namespace std;
struct student{
    string sn;
    double score;
};

int main() {
    struct student a[101],tmp;
    int i,j,n,k;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i].sn >>a[i].score;
    }
    for(i=1;i<n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j].score<a[j+1].score){
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    cout << a[k].sn<<" "<<a[k].score<<endl;
    return 0;
}
