//
//  main.cpp
//  LowestCommonAncestor
//
//  Created by Shujie Hu on 2/22/16.
//  Copyright © 2016 Shujie Hu. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        if (root == p || root == q) {
            //root is the LCA
            return root;
        } else {
            TreeNode *l = NULL;
            TreeNode *r = NULL;
            l = lowestCommonAncestor(root->left, p, q);
            r = lowestCommonAncestor(root->right, p, q);
            if (l && r) {
                //root is the LCA since q and q exist on both sides
                return root;
            } else if (!l) {
                //LCA exsist on the right  branch
                return r;
            } else if (!r) {
                return l;
            } else {
                return NULL;
            }
        }
    }
};
