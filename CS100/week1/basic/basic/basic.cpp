//
//  main.cpp
//  cs100-week1
//
//  Created by Ge, Xiao on 14/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>

void basicTypeDemo(){
    int a=1;    // 整数
    std::cout<<"a="<<a<<std::endl;
    // int a={1};
    // int a{1}
    
    double b=3.14;  // 浮点数
    std::cout<<"b="<<b<<std::endl;
    
    int data[5]={1,2,3,4,5}; // 数组：一定要指明大小，否则无法编译
    // int data[5]={}   // 全部初始化为0
    std::cout<<"data="<<data<<std::endl;
    printf("%d %d %d %d %d\n",data[0],data[1],data[2],data[3],data[4]);
    
    std::string s="abc";    // 字符串
    std::cout<<"s="<<s<<std::endl;
    std::cout<<"s[2]="<<s[2]<<std::endl;    // 字符串本质上就是字符数组
    
    // 为什么没有布尔类型？因为c++直接使用整数0和1表示布尔类型
    // 如果你一定要输出true/false，那么如下
    std::cout<<std::boolalpha<<(1==2)<<std::endl;
}

void ioDemo(){
    int a;
    char b;
    std::string s;
    
    // 1.流式输入输出
    std::cout<<"Please input one int, one char, one string"<<std::endl;
    std::cin>>a>>b>>s;
    std::cout<<"a="<<a<<" b="<<b<<" s="<<s<<std::endl;
    
    // 2.格式化输入输出
    std::cout<<std::endl<<"Please input one int, one char, one string"<<std::endl;
    scanf("%d %c %s",&a,&b,&s[0]);
    printf("a=%d b=%c s=%s\n",a,b,s.c_str());
}

using namespace std;

void basicOprDemo(){
    cout<<"5/2="<<(5/2)<<endl;  // 整数除法
    cout<<"5.0/2="<<(5.0/2)<<endl;  // 浮点数除法
    cout<<"5/2="<<((double)5/2)<<endl;  // 类型转换算符
    cout<<"5%2="<<(5%2)<<endl;  // 取模
    // cout<<"5.0%2="<<(5.0%2)<<endl;  // 编译错误
    
    int a=1, b=a++, c=++a;   // 自增算符，赋值算符
    printf("a=%d b=%d c=%d\n",a,b,c);
    a*=2;   // 运算后赋值算符
    printf("a*=2 is %d\n",a);
    
    cout<<"1>2 is "<<(1>2)<<endl;   // 记得布尔值就是0和1？
    cout<<"3!=4 is "<<boolalpha<<(3!=4)<<endl;
    cout<<"1>2 || 3!=4 is "<<(1>2 && 3!=4)<<endl;  // 逻辑运算
    
    // 混合运算
    cout<<"a++%2==1 && 3!=4 || 7>=7 is "<<(a++%2==1 && 3!=4 || 6>=7)<<endl;
}

void basicStructureDemo(){
    int a;
    cout<<"input a int a : "<<endl; // 顺序结构
    scanf("%d",&a);
    printf("a=%d\n",a);
    
    if (a%2==1){    // 分支结构
        // if (a%2) {   // 回忆一下布尔值就是0和1，所以也可以这么写。这是一种技巧，但是影响可读性，一般不推荐
        printf("%d is odd\n",a);
    }else{
        printf("%d is even\n",a);
    }
    printf("%d is %s\n",a,a%2==0?"even":"odd");    // 条件运算符。是不是觉得很拽？^^
    
    for (int i=0;i<a;i++){  // 循环结构
        printf("repeat for %d times. This is No.%d\n",a,i+1);
    }
}

void forDemo(){
    for (int i=0;i<10;i++,cout<<i<<" ");    // 循环体写到for语句
    cout<<endl;
    
    for (int i=0,j=10;i<=j;i+=2,j-=3){  // 两个循环控制变量
        cout<<"("<<i<<","<<j<<") ";
    }
    cout<<endl;
    
    for (int i=0;;i++) {   // 死循环
        cout<<"Forever running..."<<endl;
        if (i>5)
            break;  // 跳出死循环
    }
    cout<<endl;
}


int main(int argc, const char * argv[]) {
    
        std::cout << "Hello, World!\n";
    
//        basicTypeDemo();
//        ioDemo();
//        basicOprDemo();
//        basicStructureDemo();
        forDemo();
    
    return 0;
}
