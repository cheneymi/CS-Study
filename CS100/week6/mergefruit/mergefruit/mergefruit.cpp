//
//  mergeFruit.cpp
//  tree
//
//  Created by Ge, Xiao on 03/03/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
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
        if (i>1 && data[i/2]>data[i]){
            swap(data[i/2],data[i]);
            recover(i/2);
        }
        if (i*2+1<=size && data[i*2+1]<data[i] && data[i*2+1]<=data[i*2]){ // 右子树最小
            swap(data[i*2+1],data[i]);
            recover(i*2+1);
        }
        if (i*2<=size && data[i*2]<data[i] && (i*2+1>size || data[i*2]<data[i*2+1])){ // 左子树最小
            swap(data[i*2],data[i]);
            recover(i*2);
        }
    }
    
public:
    
    MinHeap(const int& n){ // 初始化
        data.empty();
        capacity=1<<n;
        size=0;
        data.reserve(capacity);
    }
    
    int removeRoot() {  // 删除根节点并返回其值
        int root= data[1];
        data[1]=data[size--];
        recover(1);
        return root;
    }
    
    void insert(int value){ // 新增一个元素
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

int mergeFruit(int data[],int n){
    int ans=0,level=0;
    for(int i=n;i>0;i>>=1,level++); // 计算能容纳n个节点的堆的高度
    MinHeap heap(level);    // 初始化堆
    for (int i=0;i<n;i++){  // 入堆
        heap.insert(data[i]);
    }
    for (int i=1;i<=n-1;i++){
        // heap.print();
        int min1=heap.removeRoot(); // 取出最小的两堆
        int min2=heap.removeRoot();
        ans+=min1+min2; // 累加
        heap.insert(min1+min2); // 插入合并后的队
    }
    return ans;
}

int main(){
    /*5
     4 3 5 7 11*/
    int n;
    scanf("%d", &n);
    int data[n];
    for (int i=0;i<n;i++){
        scanf("%d", &data[i]);
    }
    int result= mergeFruit(data, n);
    cout<<result<<endl;
}

