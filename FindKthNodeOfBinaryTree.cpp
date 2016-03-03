//
//  main.cpp
//  FindKthNodeBinaryTree
//
//  Created by Shujie Hu on 3/2/16.
//  Copyright © 2016 Shujie Hu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int v) {
        val = v;
        this->left = this->right = NULL;
    }
};
struct comparator {
    bool operator()(TreeNode* a, TreeNode *b) {
        return a->val < b->val;
    }
};
void inOrder(TreeNode* root, priority_queue<TreeNode*, vector<TreeNode*>, comparator> &q, int k) {
    if (!root) {
        return;
    }
    inOrder(root->left, q, k);
    q.push(root);
    if(q.size() > k) {
        q.pop();
    }
    inOrder(root->right, q, k);
}

TreeNode* findKthTreeNode(TreeNode *root, int k) {
    TreeNode * res;
    priority_queue<TreeNode*, vector<TreeNode*>, comparator> q;
    if (!root) {
        return NULL;
    }
    //travese the whole binary tree
    inOrder(root, q, k);
    cout << q.top()->val << endl;
    return q.top();
}
