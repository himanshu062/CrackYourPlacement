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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;

        while (root) {
            stack.push(root);
            root = root->left;
        }

        for (int i = 0; i < k - 1; ++i) {
            root = stack.top(), stack.pop();
            root = root->right;
            while (root) {
                stack.push(root);
                root = root->left;
            }
        }

        return stack.top()->val;
    }
};