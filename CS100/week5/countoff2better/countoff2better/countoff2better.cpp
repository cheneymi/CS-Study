//
//  main.cpp
//  countoff2better
//
//  Created by Ge, Xiao on 08/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include<math.h>
using namespace std;


int countoffBetter(int n) {
    int f=0;
    for (int i=1;i<=n;i++) {
        f=(f+2)%i;
    }
    return f+1;
}


int countByRecursion(int n){
    if (n==1) { // 递归边界
        return 1;
    }
    int x=countByRecursion(n/2);    // 撸掉第一轮，递推
    return n%2==0 ? x*2-1 : x*2+1;
}

int countOffBest(int n){
    int x=(int) log2(n);
    return (n-(1<<x))*2+1;
}

// Wang,Yuji
int countOffByWyj(int n){
    int p=floor (log2(n));
    return (n-(pow(2,p)))*2+1;
}

//// Zhao,Haofeng
//int countoffByZhf(int n){
//    int x=log2(n);
//    int y=pow(2, x);
//    int z=(n-y)*2+1;
//    return z;
//}

// Gao,linxiang
int countoffByGlx(int n) {
    return int(2*(n-int(pow(2,floor(log10(n)/log10(2)))))+1);
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<countoffBetter(n)<<endl;
    cout<<countByRecursion(n)<<endl;
    cout<<countOffBest(n)<<endl;
    cout<<countOffByWyj(n)<<endl;
    cout<<countoffByGlx(n)<<endl;
    return 0;
}
