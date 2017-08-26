//
//  main.cpp
//  inversepair
//
//  Created by Ge, Xiao on 24/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// 求data[head:tail]之间的逆序对数
int countInversePair(int data[],int head,int tail) {
    if (head==tail) { // 递归边界
        return 0;
    }
    int mid=(head+tail)/2;
    int result=countInversePair(data,head,mid)
                +countInversePair(data,mid+1,tail); // 左右子列结果
    // 归并排序同时计算交叉的逆序对数
    int left=head, right=mid+1;
    vector<int> tmp;
    while (left<=mid || right<=tail) {
        if (right>tail || (left<=mid && data[left]<data[right])){
            tmp.push_back(data[left++]);  // 左侧小，无逆序对
        } else{ // 右侧小，data[left:mid]都比data[right]大，形成逆序对
            tmp.push_back(data[right++]);
            result+=(mid+1-left);   // 累加逆序对数
        }
    }
    
    for (int j=head;j<=tail;j++) {  // 回填排序好的部分
        data[j]=tmp.at(j-head);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int n;  // 输入
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=countInversePair(a,0,n-1);  // 计算逆序对数
    cout<<ans<<endl;    // 输出
    return 0;
}

/* 10
 13 21 11 31 32 22 12 33 23 99 */