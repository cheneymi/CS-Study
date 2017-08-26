//
//  main.cpp
//  syntax
//
//  Created by Ge, Xiao on 11/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include "util.hpp"
#include <queue>

using namespace std;

void fileIODemo(){
    // 打开输入文件，注意改成你自己的文件的绝对路径
    freopen("/Users/xiaoge/Documents/cs100/week8/syntax/input.txt", "r", stdin);
    int a[10];

    for(int i=0;i<10;i++){  // 输入
        cin>>a[i];
        a[i]=addOne(a[i]);  // 调用util.hpp里的函数，实现在util.cpp
    }

    freopen("/Users/xiaoge/Documents/cs100/week8/syntax/output.txt", "w", stdout);   // 打开输出文件
    for(int i=0;i<10;i++){  // 输出
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void stlSortDemo(int a[],int n){
    sort(a,a+n);        // 调用系统排序（默认从小到大）
    printArray(a,5);
}

void heapSortDemo(int a[],int n){
    priority_queue<int> pq; // 使用系统封装好的优先队列类（堆）
    for(int i=0;i<n;i++){
        pq.push(a[i]);  // 入堆
    }
    for(int i=0;i<n;i++){
        cout<<pq.top()<<" ";
        pq.pop();   // 出堆
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    
    int a[5]={4,2,5,3,1};

    heapSortDemo(a,5);
//    stlSortDemo(a,5);
    
//    fileIODemo();
    return 0;
}
