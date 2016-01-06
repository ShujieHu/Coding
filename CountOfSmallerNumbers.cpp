//
//  main.cpp
//  test
//
//  Created by Shujie Hu on 12/19/15.
//  Copyright © 2015 Shujie Hu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
public:
    int start, end;
    int count;
    SegmentTree *left, *right;
    SegmentTree(int start, int end, int cnt) {
        this->start = start;
        this->end = end;
        this->count = cnt;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    SegmentTree *build(int start, int end) {
        if (start > end) {
            return NULL;
        }
        SegmentTree *root = new SegmentTree(start, end, 0);
        if (start != end) {
            int mid = (start + end) / 2;
            root->left = build(start, mid);
            root->right = build(mid + 1, end);
        } else {
            root->count = 0;
        }
        return root;
    }
    
    void modify(SegmentTree*root, int index, int val) {
        if (index == root->start && index == root->end) {
            root->count += val;
            return;
        }
        
        int mid = (root->start + root->end) / 2;
        if (index <= mid) {
            modify(root->left, index, val);
        } else {
            modify(root->right, index, val);
        }
        
    }
    
    int query(SegmentTree *root, int index) {
        if (index > root->end) {
            return root->count;
        }
        if (index < root->start) {
            return 0;
        }
        int mid = (root->start + root->end) / 2;
        if (index <= mid) {
            return query(root->left, index);
        } else {
            return query(root->right, index);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        SegmentTree* root = build(0, 10000);
        vector<int> res;
        for (int i = nums.size() - 1; i >= 0; i--) {
            modify(root, nums[i], 1);
            res.push_back(query(root, nums[i] - 1));
        }
        return res;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> nums = {5, 2, 6, 1};
    Solution sol;
    vector<int> res = sol.countSmaller(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
