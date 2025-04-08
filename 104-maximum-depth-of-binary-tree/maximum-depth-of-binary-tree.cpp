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
    int maxDepth(TreeNode* root) {
// using recursive DFS
        // if(root == nullptr) {
        //     return 0;
        // }
        // return 1 + max(maxDepth(root->left), maxDepth(root->right)); 
        // // here we are calculating the depth of left and right subtree with maxDepth method
        // // here we know the maximu depth is 1 first , from the root node.

// using Iterative BFS
    queue<TreeNode*> q;
    if (root != nullptr) {
        q.push(root);
    }

    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        // we are just traversing the tree
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front(); // the parebt or root node
            q.pop(); //pop the before hand element before going to the next level
            if(node->left != nullptr) { //checking if node->left is null or not - left subtree
                q.push(node->left);
            }
            if(node->right != nullptr) { //checking if node->right is null or not - right subtre
                q.push(node->right);
            }
        }
        level++;
    }
    return level;
    }
};