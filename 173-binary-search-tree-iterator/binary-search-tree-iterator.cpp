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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) { pushLeftsUntilNull(root); }

    int next() {
        TreeNode* root = stack.top();
        stack.pop();
        pushLeftsUntilNull(root->right);
        return root->val;
    }

    bool hasNext() { return !stack.empty(); }

private:
    stack<TreeNode*> stack;

    void pushLeftsUntilNull(TreeNode* root) {
        while (root != nullptr) {
            stack.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */