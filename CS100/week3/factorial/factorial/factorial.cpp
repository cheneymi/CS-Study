//
//  main.cpp
//  factorial
//
//  Created by Xiao Ge on 4/23/17.
//  Copyright © 2017 Xiao Ge. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int countFactorial(int n){
    double ans=0.0;
    for (int i=1;i<=n;i++){
        ans+=log10(i);
    }
    return (int)ans+1;
}

int countFactorialBetter(int n){
    double e=2.718281828;
    double pi=3.14159265358979;
    return ceil(log10(sqrt(2*pi*n)) + n*log10(n/e));
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<countFactorial(n)<<endl;
    cout<<countFactorialBetter(n)<<endl;
    return 0;
}
