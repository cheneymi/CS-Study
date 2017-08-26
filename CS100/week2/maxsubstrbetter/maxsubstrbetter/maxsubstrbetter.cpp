//
//  main.cpp
//  maxsubstrbetter
//
//  Created by Ge, Xiao on 17/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include<iostream>
using namespace std;

void countMaxSubStrBetter1(int n,int a[]){
    int max=0; // 当前最大值
    for (int left=1;left<=n;left++){ // 子串的左边界
        int sum=0; // 求和
        for (int right=left;right<=n;right++){ // 子串的右边界
            sum+=a[right];
            max= sum>max?sum:max; // 更新最大值
        }
    }
    cout<<"MaxSubStr Sum="<<max<<endl;
}

void countMaxSubStrBetter2(int n,int a[]){
    int max=0; // 当前最大值
    
    int subSum[n];
    subSum[0]=0;
    for (int i=1;i<=n;i++){ // 计算部分和
        subSum[i]=subSum[i-1]+a[i];
    }

    for (int left=1;left<=n;left++){ // 子串的左边界
        for (int right=left;right<=n;right++){ // 子串的右边界
            int sum=subSum[right]-subSum[left-1];
            max= sum>max?sum:max; // 更新最大值
        }
    }
    cout<<"MaxSubStr Sum="<<max<<endl;
}

void countMaxSubStrBest(int n,int a[]){
    int max=0,sum=0; // 当前最大值，以当前位置结尾的最大值
    for(int i=1;i<=n;i++){ // 子串的左边界
        sum=(sum>0?sum:0)+a[i]; // 如果之前的最大值是负的，就抛弃，否则就加上（递推）
        max= sum>max?sum:max;   // 更新最大值
    }
    cout<<"MaxSubStr Sum="<<max<<endl;
}

int main(int argc, const char * argv[]) {
    /*    9
     13 -21 11 -31 32 22 -12 33 23 */
    // 输入
    int n;
    scanf("%d",&n);
    int a[1000];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    countMaxSubStrBetter1(n,a);
    countMaxSubStrBetter2(n,a);
    countMaxSubStrBest(n,a);
    return 0;
}
