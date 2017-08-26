//
//  main.cpp
//  syntax
//
//  Created by Ge, Xiao on 19/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//┴┬┴┬／￣＼＿／￣＼
//┬┴┬┴▏　　▏▔▔▔▔＼ 这
//┴┬┴／＼　／　　　　　　﹨ 地
//┬┴∕　　　　　　　／　　　） 方
//┴┬▏　　　　　　　　●　　▏ 不
//┬┴▏　　　　　　　　　　　▔█◤ 错，
//┴◢██◣　　　　　　 ＼＿＿／
//┬█████◣　　　　　　　／　 让我用PP踩踩！
//┴█████████████◣
//◢██████████████▆▄
//█◤◢██◣◥█████████◤＼
//◥◢████　████████◤　　 ＼
//┴█████　██████◤　　　　　 ﹨
//┬│
//　　　│█████◤　　　　　　　　▏
//┴│　　　│ PP熊在此！借贵宝地一踩！ 　▏
//┬∕　　　∕　　　　／▔▔▔＼　　　　 ∕
//*∕＿＿_／﹨　　　∕　　　　　 ＼　　／＼
//┴┬┴┬┴┬┴ ＼＿＿＿＼　　　　 ﹨／▔＼﹨／▔＼


// ----vector（变长数组）----

void printVector(vector<int> v){    // 顺次打印以供vector
    cout<<"v=[ ";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<"]"<<endl;
}

void vectorDemo(){  // vector使用范例
    vector<int> v;
    printVector(v);
    cout<<"size="<<v.size()<<endl<<endl;    // 输出尺寸
    
    v.push_back(1); v.push_back(2); v.push_back(3); // 向后追加
    printVector(v);
    cout<<"v[1]="<<v.at(1)<<endl;   // 单个元素
    cout<<"size="<<v.size()<<endl<<endl;
    
    v.pop_back();   // 删除尾部元素
    printVector(v);
    cout<<"size="<<v.size()<<endl<<endl;
    
    v.clear();  // 清空列表
    printVector(v);
    cout<<"size="<<v.size()<<endl<<endl;
}

// ----------------扩展的分割线，以下是扩展阅读相关代码-----------------

// ----传参----

void swap1(int a,int b,int arr[]) {   // 形式参数/值参
    int tmp=a; a=b;  b=tmp;
    tmp=arr[0]; arr[0]=arr[1]; arr[1]=tmp;
    cout<<"in swap1:\ta="<<a<<" b="<<b<<" arr=["<<arr[0]<<","<<arr[1]<<"]"<<endl;
}

void swap2(int &a,int &b,int arr[]) { // 引用参数/变量参
    int tmp=a; a=b; b=tmp;
    tmp=arr[0]; arr[0]=arr[1]; arr[1]=tmp;
    cout<<"in swap2:\ta="<<a<<" b="<<b<<" arr=["<<arr[0]<<","<<arr[1]<<"]"<<endl;
}

void paramDemo(){
    int a=1,b=2;
    int arr[2]={3,4};
    cout<<"outside:\ta="<<a<<" b="<<b<<" arr=["<<arr[0]<<","<<arr[1]<<"]"<<endl;
    
    swap1(a,b,arr);
    cout<<"outside:\ta="<<a<<" b="<<b<<" arr=["<<arr[0]<<","<<arr[1]<<"]"<<endl;
    swap2(a,b,arr);
    cout<<"outside:\ta="<<a<<" b="<<b<<" arr=["<<arr[0]<<","<<arr[1]<<"]"<<endl;
}

// ----模板----

template<class T>
T add(T a,T b){
    return a+b;
}

void templdateDemo(){
    std::cout<<add<int>(1,2)<<std::endl;
    std::cout<<add<double>(1.1,2.2)<<std::endl;
}

// -------------------------------------------------------

int main(int argc, const char * argv[]) {

    vectorDemo();
//    paramDemo();
//    templdateDemo();
    return 0;
}
