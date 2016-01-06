//
//  main.cpp
//  Leetcode_CreateMaximumNumber
//
//  Created by Shujie Hu on 12/30/15.
//  Copyright © 2015 Shujie Hu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> v1 = maxArray(nums1, i);
            vector<int> v2 = maxArray(nums2, k - i);
            vector<int> candidate = merge(v1, v2);
            if (compare(candidate, res)) {
                res = candidate;
            }
        }
        return res;
    }
    //compare the value represented by both arrays, return true if v1>= v2 else return false
    bool compare(vector<int> v1, vector<int> v2) {
        if (v1.size() > v2.size()) {
            return true;
        }
        
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] < v2[i]) {
                return false;
            }
            
            if(v1[i] > v2[i]) {
                return true;
            }
        }
        return true;
    }
    
    //maxArray is used to get the maximum subarray with size k from nums with preserving original order
    vector<int> maxArray(vector<int> nums, int k) {
        int n = nums.size();
        vector<int> res;
        stack<int> stk;
        if (n < k || k == 0) {
            return res;
        }
        //based on the stack, establish a non-increasing order
        //keeping finding the largest value for the first element as long as the size remaining is no-smaller than k
        //stack is used to store all k elements
        for (int i = 0; i < n; i++) {
            //j is used for the count of numbers already stored in stack
            // compare the top elemnt of stack with nums[i]
            while (!stk.empty() && stk.top() < nums[i] && n - i + stk.size() > k) {
                stk.pop();
            }
            
            if (stk.size() < k) {
                stk.push(nums[i]);
            }
        }
        
        while(!stk.empty()) {
            int t = stk.top();
            stk.pop();
            res.push_back(t);
        }
        
        //use vector<int> to store all the information in stack
        //swap two elements considering the sequence of the stack
//        for (int i = 0; i < k / 2; i++) {
//            int t = res[i];
//            res[i] = res[k - 1 - i];
//            res[k - 1 - i] = t;
//        }
        reverse(res.begin(),res.end());
        return res;
    }
    
    //merge two arrays without deleting any element
    //to obtain the maximum value
    vector<int> merge(vector<int>nums1, vector<int>nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int> res;
        int i = 0;
        int j = 0;
        
        while (i < m && j < n) {
            //both are not fully merged in
            if (nums1[i] >= nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while (i == m && j < n) {
            res.push_back(nums2[j]);
            j++;
        }
        while (i < m && j == n) {
            res.push_back(nums1[i]);
            i++;
        }
        return res;
    }
    
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;
    Solution sol;
    vector<int> res = sol.maxNumber(nums1, nums2, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}

