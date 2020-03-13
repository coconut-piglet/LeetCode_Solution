class Solution {
private:
    typedef struct NodeInfo {
        int left;
        int right;
        string combination;
    } NodeInfo;
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        stack<NodeInfo*> nodes;
        NodeInfo *root = new NodeInfo;
        root->left = n;
        root->right = 0;
        root->combination = "";
        nodes.push(root);
        while (!nodes.empty()) {
            NodeInfo* curNode = nodes.top();// get the first node
            nodes.pop();// remove it
            if (curNode -> left == 0 && curNode -> right == 0) {// if all '(' and ')' are used
                ret.push_back(curNode -> combination);// insert it into the return vector
            }
            if (curNode->left > 0) {// '(' is not used up
                NodeInfo *newNode = new NodeInfo;
                newNode->left = curNode->left - 1;// use this '('
                newNode->right = curNode->right + 1;// and accordingly add one ')'
                newNode->combination = curNode->combination + "(";
                nodes.push(newNode);// add subnode to the node list
            }
            if (curNode->right > 0) {// ')' is not used up
                NodeInfo *newNode = new NodeInfo;// use this ')'
                newNode->left = curNode->left;// adding ')' won't affect the number of '('
                newNode->right = curNode->right - 1;// decrease the number of ')'
                newNode->combination = curNode->combination + ")";
                nodes.push(newNode);// add subnode to the node list
            }
            delete curNode;// delete temp curNode to save space
        }
        return ret;
    }
};