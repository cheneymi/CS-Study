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
        current->next=current->next->next;  // 删除下一个节点（报2）
        current=current->next;  // 挪到下一个节点（报1，注意报2的已经删掉了）
    }
    return current->id;
}

// 使用数组的解法（供对比）
int countByArray(int n){
    vector<int> v=vector<int>(n); // 1表示已经出列，初始都是0
    int current=0;
    for (int i=1;i<=n-1;i++){
        for (;v[current]==1;) { // 找下一个0
            current=(current+1)%n;
        }
        current=(current+1)%n;  // 报数1，留在队列中
        for (;v[current]==1;) { // 再找下一个0
            current=(current+1)%n;
        }
        v[current]=1;   // 报数2，出列
    }
    for (;v[current];) {
        current=(current+1)%n;
    }
    return current+1;
}


int main(int argc, const char * argv[]) {
    int n;
    cin>>n;

    cout<<countByLink(n)<<endl;
    cout<<countByArray(n)<<endl;

    return 0;
}
