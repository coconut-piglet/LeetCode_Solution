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
        if (root -> left != nullptr) solveInorderTraversal(root -> left, ret);
        ret.push_back(root -> val);
        if (root -> right != nullptr) solveInorderTraversal(root -> right, ret);
    }
;};