#include <iostream>
using namespace std;

int main() {
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='a'&&a[i]<='z'){
            cout<<char(a[i]-32);
        }
        if(a[i]>='A'&&a[i]<='Z'){
            cout<<char(a[i]+32);
        }
    }
    cout<<endl;
    return 0;
}
