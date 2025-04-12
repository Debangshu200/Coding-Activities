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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true; // if subtree is empty, then empty subtree can be part of root tree
        if(!root) return false; // if root tree is empty then subtree can't be there in the root tree.

        return sameTree(root, subRoot) || 
        isSubtree(root->left, subRoot) || 
        isSubtree(root->right, subRoot); //1.Checking if it passes all the checks in sameTree function, 
                                         //2.checking if the left subtree of root tree same as subRoot, 
                                         //3. checking if the right subtree of root tree same as subRoot.
    }
    bool sameTree(TreeNode* t, TreeNode* s) {
        if(!t && !s) return true; // checking if the two roots of 'both'- trees ar empty then return true.
        if(!t || !s) return false; // checking if one of the roots of the tree is empty then return false.

        return s->val == t->val && //checkig if the value & data type of the roots of both the tree are same 
            sameTree(s->left, t->left) && // checking if root->left of s and t are same.
            sameTree(s->right, t->right); // checking if root->right of s and t are same.
    }
};