//  main.cpp
//  ImplementStackByQueues
//
//  Created by Shujie Hu on 3/15/16.
//  Copyright © 2016 Shujie Hu. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
    int val;
    queue<int> q1, q2;
    
    void push(int v) {
        q1.push(v);
    }
    int top() {
        if (q1.empty()) {
            return INT_MIN;
        }
        while (q1.size() > 1) {
            int t = q1.front();
            q1.pop();
            q2.push(t);
        }
        return q1.front();
    }
    
    void pop() {
        if (q1.empty()) {
            cout << "empty!" << endl;
        } else {
            while (q1.size() > 1) {
                int t = q1.front();
                q1.pop();
                q2.push(t);
            }
            q1.pop();
            swap(q1, q2);
        }
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

class MinStack : public Stack {
public:
    Stack stk, minstk;
    void push(int v) {
        stk.push(v);
        if (minstk.empty() || minstk.top() >= v) {
            minstk.push(v);
        }
    }
    int top() {
        return stk.top();
    }
    void pop() {
        int t = stk.top();
        stk.pop();
        if (t == minstk.top()) {
            minstk.pop();
        }
    }
    int getMin() {
        return minstk.top();
    }
};
