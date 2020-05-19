class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        len = s.length();
        input = s;
        string mask(len + 3, '*');
        ipAddr = mask;
        src = 0;
        dst = 0;
        process(0);
        return ret;
    }
private:
    int len;
    int src;
    int dst;
    string input;
    string ipAddr;
    
    void process(int num) {
        
    }
};