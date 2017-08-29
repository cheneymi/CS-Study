#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n,x,m;//n,x,m
    int months=0;//months
    cin>>n>>x>>m;//enter
    if(n-x>0) months=ceil((n-x)/m); //calcaulate months
    cout<<months<<endl;//output
    return 0;//return
}
