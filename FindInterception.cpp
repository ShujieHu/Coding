//  main.cpp
//  BloombergTest
//
//  Created by Shujie Hu on 3/17/16.
//  Copyright © 2016 Shujie Hu. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    int maxV;
    int i = 0;
public:
    queue<int> findInterSection(vector<queue<int>> arr) {
        queue<int> res;
        i = 0;
        //initialize 
        maxV = arr[0].front();
        while(!arr[i].empty()) {
            // not empty
            if (arr[i].front() > maxV) {
                //update maxV and i
                maxV = arr[i].front();
                i = 0;
            } else if (arr[i].front() < maxV) {
                arr[i].pop();
            } else {
                arr[i].pop();
                //when they equal move to the next i
                i++;
                if (i == arr.size()) {
                    //have found the common intersectino between all queues
                    res.push(maxV);
                    i = 0;
                }
            }
        }
        
        return res;
    }
    
};
