class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        len = s.length() - 1;
        inputStr = s;
        string ip(len + 4, '*');
        vector<string> ret;
        solveProblem(ip, 0, 0, 0, 3, ret);
        return ret;
    }
private:
    int len;
    string inputStr;
    void solveProblem(string & outputIp, int currentNum, int src, int dst, int leftNum, vector<string> &ret) {
        
        /* case 0: cases like 1111 => 111.1 will cause src to reach end too early */
        if (src > len) return;
        
        currentNum = currentNum * 10 + inputStr[src] - '0';
        
        if (leftNum == 0) {
            /* case 1:if the last number start with 0, but str hasn't reach its end, abort */
            if (currentNum == 0 && src < len) return;
            
            /* calculate the last number */
            for (int i = src + 1; i <= len; i++) {
                currentNum = currentNum * 10 + inputStr[i] - '0';
                
                /* case 2: if the last number excceeds 255, abort */
                if (currentNum > 255) return;
            }
            
            /* case 3: if control reaches here, a valid ip is restored */
            while (src <= len) {
                outputIp[dst] = inputStr[src];
                src++;
                dst++;
            }
            ret.push_back(outputIp);
            return;
        }
        
        /* for the first three number */
        if (currentNum < 256) {
            outputIp[dst] = inputStr[src];
            
            /* here we can access dst + 1 safely */
            outputIp[dst + 1] = '.';
            
            /* branch 1: stop current number and go for the next one */
            solveProblem(outputIp, 0, src + 1, dst + 2, leftNum - 1, ret);
            
            /* branch 2: for numbers not start with 0, alternatively could expand to the next str */
            if (currentNum) solveProblem(outputIp, currentNum, src + 1, dst + 1, leftNum, ret);
        }
        
        return;
    }
};
