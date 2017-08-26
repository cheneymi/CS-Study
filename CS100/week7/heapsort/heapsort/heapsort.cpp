//
//  main.cpp
//  heapsort
//
//  Created by Ge, Xiao on 08/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
private:  // private表示只有在class内部可访问
    vector<int> data;   // 数据，因为是满二叉树，用数组存就可以
    int capacity,size;  // 最大容量，实际数量
    
    void swap(int &a,int &b){   // 交换整数辅助函数
        a=a+b;
        b=a-b;
        a=a-b;
    }
    
    // 从节点i开始恢复堆的特性
    void recover(int i){
        if (i>1 && data[i/2]<data[i]){
            swap(data[i/2],data[i]);
            recover(i/2);
        }
        if (i*2+1<=size && data[i*2+1]>data[i] && data[i*2+1]>=data[i*2]){ // 右子树最大
            swap(data[i*2+1],data[i]);
            recover(i*2+1);
        }
        if (i*2<=size && data[i*2]>data[i] && (i*2+1>size || data[i*2]>data[i*2+1])){ // 左子树最大
            swap(data[i*2],data[i]);
            recover(i*2);
        }
    }
    
public:

    MaxHeap(const int& depth){ // 初始化
        data.empty();
        capacity=1<<depth;
        size=0;
        data.reserve(capacity);
    }
    
    int pop() {  // 删除根节点并返回其值
        int root= data[1];
        data[1]=data[size--];
        recover(1);
        return root;
    }
    
    void push(int value){ // 新增一个元素
        data[++size]=value;
        recover(size);
    }
    
    void print(){   // 用友好的方式输出堆的内容
        for (int i=1;i<=size;i++){
            int left=i*2<=size?data[i*2]:-1;
            int right=i*2+1<=size?data[i*2+1]:-1;
            cout<<data[i]<<"("<<left<<","<<right<<")"<<endl;
        }
        cout<<endl;
    }
};


int main(int argc, const char * argv[]) {
    /* 14
     53 542 5 63 14 217 154 748 616 742 111 412 452 134*/
    
    // 输入
    int n;
    cin>>n;

    int depth=1,x=1;    // 估算堆的深度
    for (;x<n;depth++,x*=2);
    MaxHeap heap=MaxHeap(depth);    // 建堆
    
    for(int i=0;i<n;i++){
        cin>>x;
        heap.push(x);     // 依次入堆
    }
    
    for(int i=0;i<n;i++){
        cout<<heap.pop()<<" ";   // 依次出堆
    }
    cout<<endl;
    return 0;
}
