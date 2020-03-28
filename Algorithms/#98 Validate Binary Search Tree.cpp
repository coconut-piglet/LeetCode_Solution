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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        int prev = 0;
        bool hasPrev = false;
        return inorderCheck(root, prev, hasPrev);
    }
private:
    bool inorderCheck(TreeNode* root, int &prev, bool &hasPrev) {
        if (root == nullptr) return true;
        if (!inorderCheck(root -> left, prev, hasPrev)) return false;
        if (hasPrev && root -> val <= prev) return false;
        prev = root -> val;
        hasPrev = true;
        return inorderCheck(root -> right, prev, hasPrev);
    }
};