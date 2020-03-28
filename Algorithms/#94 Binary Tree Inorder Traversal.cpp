/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root != nullptr) solveInorderTraversal(root, ret);
        return ret;
    }
private:
    void solveInorderTraversal(TreeNode* root, vector<int> &ret) {
        if (root == nullptr) return;
        solveInorderTraversal(root -> left, ret);
        ret.push_back(root -> val);
        solveInorderTraversal(root -> right, ret);
    }
};