//
//  main.cpp
//  oneinthree
//
//  Created by Ge, Xiao on 10/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
using namespace std;

int findOneNumberInThrees2(int n){
    int lowerbits=0,higherbits=0,bothone,a;
    for(int i=0;i<n;i++){
        cin>>a; // 输入
        higherbits ^= (lowerbits&a);   // 二进制加，高位运算（含进位）
        lowerbits ^= a;    // 二进制加，低位运算

        bothone=higherbits&lowerbits;   // 标记是否达到(1,1)
        // 满三归位：如果成为(1,1)，要转回成(0,0)，否则不变
        higherbits&=~bothone;   // 这里语法有点装逼，只需要记住取反位运算符(~)优先级最高
        lowerbits&=~bothone;
        // 这是日志，有兴趣可以看看输出些什么
        cout<<"a="<<a<<" bits="<<higherbits<<lowerbits<<endl;
    }
    return lowerbits&~higherbits;
}

int main(int argc, const char * argv[]) {
    /*4
     1 1 1 1*/
    // 如果你看不太懂建议打开日志那行，然后用上面这组数据测，容易看出端倪

    /*10
     5 4 4 7 7 4 6 5 5 7*/
    int n;
    cin>>n;
    cout<<findOneNumberInThrees2(n)<<endl;
    return 0;
}
