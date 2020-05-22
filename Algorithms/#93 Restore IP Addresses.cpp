class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        len = s.length();
        inputStr = s;
        string ip(len + 3, '*');
        vector<string> ret;
        solveProblem(ip, 0, 0, 0, 4, ret);
        return ret;
    }
private:
    int len;
    string inputStr;
    void solveProblem(string & outputIp, int currentNum, int src, int dst, int leftNum, vector<string> &ret) {
        if (leftNum == 0) {
            cout << outputIp;
            if (src == len) {
                ret.push_back(outputIp);
            }
            else {
                return;
            }
        }
        if (src >= len) {
            return;
        }
        currentNum = currentNum * 10 + inputStr[src] - '0';
        if (currentNum == 0) { // case .0. should jump to next number
            outputIp[dst] = inputStr[src];
            outputIp[dst + 1] = '.';
            solveProblem(outputIp, 0, src + 1, dst + 2, leftNum - 1, ret);
        }
        else if (currentNum > 255) { // case .256. or .1234. should stop expanding current number
            return;
        }
        else { // .XX. calculate next number and then expand current number
            outputIp[dst] = inputStr[src];
            outputIp[dst + 1] = '.';
            solveProblem(outputIp, 0, src + 1, dst + 2, leftNum - 1, ret);
            solveProblem(outputIp, currentNum, src + 1, dst + 1, leftNum, ret);
        }
    }
};
