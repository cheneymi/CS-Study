//
//  main.cpp
//  fallingballbetter
//
//  Created by Ge, Xiao on 11/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

int calc(int d,int n) { // 递归方式
    if (d==1) {
        return 1;
    }
    return n%2==1 ? calc(d-1,n/2+1)+(1<<(d-2)) : calc(d-1,n/2)+(1<<(d-1));
}

int calc2(int d,int n){ // 非递归方式（二进制逆序）
    int pos=0;
    n=(n-1)%(1<<(d-1));
    for (int i=0;i<d-1;i++){
        pos=(pos<<1)+(n&1);
        n>>=1;
    }
    return pos+(1<<(d-1));
}

// Wang,Yuji
int calc3(int d,int n) {
    int k = 1;
    for(int i = 0; i < d-1; i++){
        if (n%2) {
            k *= 2;
            n = (n+1)/2;
        } else {
            k = k*2+1;
            n /= 2;
        }
    }
    return k;
}

int main(int argc, const char * argv[]) {
    int d, n;
    cin>>d>>n;
    cout<<calc(d,n)<<endl;
    cout<<calc2(d,n)<<endl;
    cout<<calc3(d,n)<<endl;
    return 0;
}
