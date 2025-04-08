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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // either root node null or have same elements
        if(p == q)
            return true;
        // check if root of p and q is not null -> , then their val is same or not
        if (!p || !q || p->val != q->val) 
            return false;
        // return true, if left and right subtree is same, else false..
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }
};