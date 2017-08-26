//
//  main.cpp
//  sorting
//
//  Created by Ge, Xiao on 19/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void sortBySelect(int data[],int n){
    for (int i=0;i<n-1;i++){
        int least=i;
        // 循环选择i..n-1中最小的元素
        for (int j=i+1;j<n;j++){
            if (data[j] > data[least]){
                least=j;
            }
        }
        // 交换元素i和元素least
        int tmp=data[i];
        data[i]=data[least];
        data[least]=tmp;
    }
}

void sortByMerge(int data[],int head,int tail){
    if (head==tail) { // 递归边界
        return;
    }
    int mid=(head+tail)/2;
    // cerr<<"head="<<head<<" mid="<<mid<<" tail="<<tail<<"\n";
    sortByMerge(data,head,mid);   // 排序左子列
    sortByMerge(data,mid+1,tail); // 排序右子列
    
    int left=head, right=mid+1, i=0;    // 左右两个游标
    int tmp[tail-head+1];   // 存放临时结果
    while (left<=mid || right<=tail) {  // 归并过程
        // 把左右游标中较小的一个放入tmp的当前位置
        if (right>tail|| (left<=mid && data[left]<data[right])){
            tmp[i++]=data[left++];
        } else{
            tmp[i++]=data[right++];
        }
    }
    // 将tmp（排好序的）回填到原数组的head到tail位置
    for (int j=head;j<=tail;j++){
        data[j]=tmp[j-head];
    }
}

void baseSort(int data[],int n){
    vector<int> buckets[10];  // 10个桶（队列）
    int max=data[0]; // 找最大元素作为循环边界
    for (int i=1;i<n;i++) {
        max=data[i]>max?data[i]:max;
    }
    
    for (int base=1;base<=max;base*=10) { // 从低祷告循环每一位，base每次*10直到大于所有元素
        for(int i=0;i<n;i++) {
            int index=(data[i]/base) % 10; // 提取一位数
            buckets[index].push_back(data[i]); // 顺序插入对应桶
        }
        
        for (int i=0,k=0;k<10;k++) {    // k是桶下标，i是数组下标，注意i++是在内循环里
            vector<int> vec=buckets[k]; // 依次提取每个桶
            for(int j=0;j<vec.size();j++) { // 依次从桶里取出数据放回到数列
                data[i++]=vec.at(j);
            }
            buckets[k].clear(); // 清空桶，准备下一次
        }
    }
}

int main(int argc, const char * argv[]) {
    /* 14
     53 542 5 63 14 217 154 748 616 742 111 412 452 134*/
    
    // 输入
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
//    sortBySelect(a,n); // 选择排序
//    sortByMerge(a,0,n-1); // 归并排序
    baseSort(a,n);  // 基数排序
    
    // 输出
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
