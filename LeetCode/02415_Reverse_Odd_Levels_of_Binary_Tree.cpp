//TODO - to find better CPU and Memory performance

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

TreeNode* cloneNode(TreeNode* node) {
    if (!node) return nullptr;

    return new TreeNode(
        node->val,
        cloneNode(node->left),
        cloneNode(node->right)
    );
}

void mirrorOdds(TreeNode* a, TreeNode* b, int lvl) {
    if (a->left == nullptr) return;
    if(lvl % 2 == 0) {
        b->right->val = a->left->val;
        b->left->val = a->right->val;
    }
    lvl++;
    mirrorOdds(a->left, b->right, lvl);
    mirrorOdds(a->right, b->left, lvl);
}

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        TreeNode* mirror_root = cloneNode(root);
        mirrorOdds(root, mirror_root, 0);
        return mirror_root;
    }
};