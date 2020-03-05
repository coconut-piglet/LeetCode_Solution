class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        parentheses.push('*'); // if it's empty and the first char is the right half, will cause error
        for (char token : s) {
            switch (token) {
                case '(':
                    parentheses.push('(');
                    break;
                case ')':
                    if (parentheses.top() != '(') return false;
                    parentheses.pop();
                    break;
                case '{':
                    parentheses.push('{');
                    break;
                case '}':
                    if (parentheses.top() != '{') return false;
                    parentheses.pop();
                    break;
                case '[':
                    parentheses.push('[');
                    break;
                case ']':
                    if (parentheses.top() != '[') return false;
                    parentheses.pop();
                    break;
                default:
                    return false;
            }
        }
        if (parentheses.size() != 1) return false;
        return true;
    }
};