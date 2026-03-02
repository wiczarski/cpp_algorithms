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

bool check_node(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b == nullptr) return true;
    if ((a == nullptr && b != nullptr) || (a != nullptr && b == nullptr)) return false;
    if (a->val != b->val) return false;
    return check_node(a->left, b->left) && check_node(a->right, b->right);
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check_node(p, q);;
    }
};