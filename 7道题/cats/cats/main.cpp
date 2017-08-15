#include <iostream>
using namespace std;

int main() {
    long long cats=10;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cats=cats/3+cats;
    }
    cout<<cats<<endl;
    return 0;
}
