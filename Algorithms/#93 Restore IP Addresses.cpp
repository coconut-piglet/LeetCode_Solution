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
            if (src == len) { // exit 0: a valid ip address
                ret.push_back(outputIp);
                return;
            }
            else { // exit 1: input string not used up
                return;
            }
        }
        if (src >= len) { // exit 2: input string too short
            return;
        }
        
        currentNum = currentNum * 10 + inputStr[src] - '0';
        
        if (currentNum < 256) {
            outputIp[dst] = inputStr[src];
            if (leftNum > 1) outputIp[dst + 1] = '.';
            solveProblem(outputIp, 0, src + 1, dst + 2, leftNum - 1, ret);
            if (currentNum > 0) solveProblem(outputIp, currentNum, src + 1, dst + 1, leftNum, ret);
        }
    }
};
