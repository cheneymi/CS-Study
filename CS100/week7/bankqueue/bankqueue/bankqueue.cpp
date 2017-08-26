//
//  bankqueue.cpp
//  priority queue
//
//  Created by Li,YiShu on 05/21/2017.
//  Copyright 2017 Ge, Xiao. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct nodeX {
    int no;
    int arriveTime;
    int priority;
    int period;
};

struct NodeCmp {
    //重写operator()方法, operator()(参数1，...)
    bool operator()(const nodeX &na, const nodeX &nb) {
        if (na.priority != nb.priority)
            return na.priority <= nb.priority;
        else
            return na.arriveTime <= nb.arriveTime;
    }
};

int main() {
    /*5
     0 1 10
     2 1 10
     5 3 10
     7 2 5
     11 3 5*/
    vector<nodeX> data;
    priority_queue<nodeX, vector<nodeX>, NodeCmp> a;
    int n;
    scanf("%d", &n);
    data.reserve(n);
    for (int i = 0; i<n; i++) {
        nodeX x;
        x.no = i+1;
        scanf("%d%d%d", &x.arriveTime, &x.priority, &x.period);
        data.push_back (x);
    }
    int j = 0; nodeX y; // data[j]是下一个到达的人
    int timeline = 0;  // 时间线
    while (j<n||!a.empty()) {
        if (j<n && data[j].arriveTime <= timeline) {   //start之前有人到达
            a.push(data[j++]);
        }else if(a.empty()){    // 无人等待，窗口空闲，时间线推进到下一个人到来
            timeline=data[j].arriveTime;
            a.push(data[j++]);
        }else{ // start之前无新的人到，时间线推进到下一个人办完
            y=a.top();
            cout << y.no << " ";
            timeline += y.period;
            a.pop();
        }
    }
    cout<<endl;
    return 0;
}
