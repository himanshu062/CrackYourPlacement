/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pred = nullptr;
        TreeNode* x = nullptr; 
        TreeNode* y = nullptr;
        stack<TreeNode*> stack;
        while (root != nullptr || !stack.empty()) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top(), stack.pop();
            if (pred && root->val < pred->val) {
                y = root;
                if (x == nullptr)
                    x = pred;
            }
            pred = root;
            root = root->right;
        }
        swap(x, y);
    }
    void swap(TreeNode* x, TreeNode* y) {
        const int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
};