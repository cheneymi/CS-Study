//
//  main.cpp
//  oneintwo
//
//  Created by Ge, Xiao on 18/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

int findOneNumberInTwos(int n){
    int result=0,a;
    for (int i=0;i<n;i++){
        cin>>a; // 输入第i个数
        result ^= a;    // 累积异或
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    /*11
     5 3 2 4 2 7 4 6 5 3 7*/
    cout<<findOneNumberInTwos(n)<<endl;
    return 0;
}
