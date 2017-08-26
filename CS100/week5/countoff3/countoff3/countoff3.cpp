//
//  main.cpp
//  countoff
//
//  Created by Ge, Xiao on 28/04/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Node {    // 链表的节点类
public:
    int id; // 编号
    Node* next=0;   // 指向下一个节点的指针
    Node(int id0){  // 初始化函数
        id=id0;
    }
};

// Shao,Yicheng
int countByLinkBySyc(int n) {
    Node* head = new Node(1);
    Node* tail = head;
    
    for(int i = 2; i <= n; i++) { // 创建链表
        tail->next = new Node(i);
        tail = tail->next;
    }
    
    tail->next = head;  // 连接成环
    Node* current = head; // 开始报数（当前节点报1）
    
    for(int i = 1; i <= n - 1; i++) {
        current = current->next;
        current->next = current->next->next;
        current = current->next;
    }
    
    return current->id;
}

// 使链表解法
int countByLink(int n){
    Node* head=new Node(1);
    Node* tail=head;
    
    for (int i=2;i<=n;i++){  // 创建链表
        tail->next=new Node(i);
        tail=tail->next;
    }
    tail->next=head;    // 连接成环
    
    Node* current=head; // 开始报数（当前节点报1）
    for (int i=1;i<=n-1;i++){
        cout<<"current="<<current->id<<" next="<<current->next->id<<endl;
        current->next->next=current->next->next->next;  // 删除下一个节点（报3）
        current=current->next->next;  // 挪到下2个节点（报1,2,注意报3的已经删掉了）
        cout<<"  current="<<current->id<<" next="<<current->next->id<<endl;
    }
    return current->id;
}

// Zhang,Xiaozhou（伪代码）


// Su,Ruizhe

void input(int[1000],int);
int wipe(int[1000],int);

int countoffBySrz(int n) {
    int num[1000],r;
    input(num,n); //为1-n号同学都标志在队
    r=wipe(num,n); //游戏过程
    return r;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<countByLink(n)<<endl;
//    cout<<countByLinkBySyc(n)<<endl;
//    cout<<countoffBySrz(n)<<endl;
    return 0;
}

//把1-n号同学都标志在队
void input(int *p_num,int n) {
    int i;
    for(i=0;i<n;i++)
        *(p_num+i)=1;
}

//游戏过程,k为出局人数,j为当前报数
int wipe(int*p_num,int n) {
    int i,j=0,k=0;  // 人的id，当前报的数，已出圈的人数
    while(1)  {
        for(i=0;i<n;i++) {
            j=j+*(p_num+i);
            if(j==3) {
                *(p_num+i)=0;
                k++;
                if(k==n-1){
                    printf("\n");
                    for(i=0;i<n;i++)
                        if(*(p_num+i)==1)
                            return i+1;
                }
                j=0;
            }
        }
    }
}
