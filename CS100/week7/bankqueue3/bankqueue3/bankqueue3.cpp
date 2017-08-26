//
//  main.cpp
//  bankqueue
//
//  Created by Ge, Xiao on 10/05/2017.
//  Copyright © 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Person {  // 储存一个人的信息
public:
    int id,arrive,priority,duration;   // id,到达时间,优先级,处理时间
    Person(){}
    Person(int id0,int a,int p,int d){  // 构造函数
        id=id0; arrive=a; priority=p; duration=d;
    }

    bool operator > (Person other) { // 比较优先级
        return (priority>other.priority || (priority==other.priority && arrive<other.arrive));
    }

};

class Event {   // 事件信息
public:
    int time,isArrival; // time是事件发生时间，isArrival表示是到达时间还是完成事件
    Person person;
    
    Event(){}
    Event(const int& time0,const int& isArrival0,const Person& person0){
        time=time0; isArrival=isArrival0;
        person=person0;
    }
    bool operator > (Event other) const { // 比较优先级
        return time<other.time;
    }
};

template<class T>
class MaxHeap{ // 基于优先级的最大堆
private:  // private表示只有在class内部可访问
    vector<T> data;   // 数据，因为是满二叉树，用数组存就可以
    int capacity,size;  // 最大容量，实际数量
    
    void swap(T &a,T &b){   // 交换整数辅助函数
        T tmp=a; a=b; b=tmp;
    }
    
    // 从节点i开始恢复堆的特性（与例题唯一不同是改用priorTo比较大小）
    void recover(int i){
        if (i>1 && data[i]>data[i/2]){
            swap(data[i/2],data[i]);
            recover(i/2);
        }
        if (i*2+1<=size && data[i*2+1]>data[i] && data[i*2+1]>data[i*2]){ // 右子树最大
            swap(data[i*2+1],data[i]);
            recover(i*2+1);
        }
        if (i*2<=size && data[i*2]>data[i] && (i*2+1>size || data[i*2]>data[i*2+1])){ // 左子树最大
            swap(data[i*2],data[i]);
            recover(i*2);
        }
    }

    int getDepth(int n){    // 估算堆的深度
        int depth=1;
        for (int x=1;x<n;x<<=1,depth++);
        return depth;
    }

public:
    MaxHeap(const int& n){ // 初始化
        int depth=getDepth(n);
        data.empty();
        capacity=1<<depth;
        size=0;
        data=vector<T>(capacity);
    }
    
    T pop() {  // 删除根节点并返回其值
        T root= data[1];
        data[1]=data[size--];
        recover(1);
        return root;
    }
    
    void push(T value){ // 新增一个元素
        data[++size]=value;
        recover(size);
    }
    
    int empty(){
        return size==0;
    }
    int getSize(){
        return size;
    }
};


int main(int argc, const char * argv[]) {
    /*5
     0 1 10
     2 1 10
     5 3 10
     7 2 5
     11 3 5*/
    int n;
    cin>>n;
    int a,p,t;
    vector<int> ans=vector<int>();  // 结果存放
    MaxHeap<Person> waiting=MaxHeap<Person>(n); // 等待集合，以优先级为序的优先队列
    MaxHeap<Event> events=MaxHeap<Event>(2*n);   // 事件集合，以时间为序的优先队列
    
    for (int i=1;i<=n;i++){
        cin>>a>>p>>t;   // 输入每个人到达信息，生成n个到达事件
        events.push(Event(a,1,Person(i,a,p,t)));
    }
    
    int workingID=0;    // 当前办理的人Id，0表示无人办理
    while (!events.empty()){    // （按时间顺序）依次处理事件
        Event event=events.pop();   // 出堆
        Person person=event.person;
        cout<<"Event: Time="<<event.time<<" Person "<<person.id<<(event.isArrival?" arrive":" finish")<<". "<<waiting.getSize()<<" people waiting. Processing: "<<workingID<<endl; // 日志

        if (event.isArrival){   // 处理达到事件
            if (workingID==0) {  // 无人正在办理
                workingID=person.id; // 新来的直接办理
                ans.push_back(person.id);   // 记录结果
                events.push(Event(event.time+person.duration,0,person)); // 生成一个完成事件
            } else { // 有人正在办理，进入等待集合
                waiting.push(person);
            }
        } else {  // 处理完成事件
            if (!waiting.empty()) { // 有人在等待
                Person nextPerson=waiting.pop();    // 出堆等待集合中优先级最高的人
                workingID = nextPerson.id;  // 开始办理nextPerson
                ans.push_back(nextPerson.id);   // 记录结果
                // 生成一个完成事件
                events.push(Event(event.time + nextPerson.duration,0,nextPerson));
            } else {    // 无人等待
                workingID = 0; // 进入空闲状态
            }
        }
        cout<<" -->"<<waiting.getSize()<<" people waiting. Processing: "<<workingID<<endl; // 日志
    }
    
    for (int i=0;i<n;i++){ // 输出
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
