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
  bool isBalanced(TreeNode* root) {
    return maxDepth(root) != -1;
  }

 private:
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;

    const int left = maxDepth(root->left);
    if (left == -1)
      return -1;
    const int right = maxDepth(root->right);
    if (right == -1)
      return -1;
    if (abs(left - right) > 1)
      return -1;

    return 1 + max(left, right);
  }
};