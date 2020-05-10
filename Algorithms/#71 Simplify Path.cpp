class Solution {
public:
    string simplifyPath(string path) {
        int total, start, len;
        string dir;
        list<string> buf;
        
        start = 1;
        path += '/';
        total = path.length();
        
        for (int i = 1; i < total; i++) {
            
            if (path[i] == '/') {
                len = i - start;
                dir = path.substr(start, len);
                start = i + 1;
                
                if (dir.length() == 0 || dir.compare(".") == 0) {
                    continue;
                }
                else if (dir.compare("..") == 0) {
                    if (!buf.empty()) buf.pop_back();
                }
                else {
                    buf.push_back(dir);
                }
            }
            
        }
        
        if (buf.empty()) return "/";
        
        string ret = "";
        for (string name : buf) {
            ret += "/";
            ret += name;
        }
        
        return ret;
    }
};class Solution {
public:
    string simplifyPath(string path) {
        int total, start, len;
        string dir;
        list<string> buf;
        
        start = 1;
        path += '/';
        total = path.length();
        
        for (int i = 1; i < total; i++) {
            
            if (path[i] == '/') {
                len = i - start;
                dir = path.substr(start, len);
                start = i + 1;
                
                if (dir.length() == 0 || dir.compare(".") == 0) {
                    continue;
                }
                else if (dir.compare("..") == 0) {
                    if (!buf.empty()) buf.pop_back();
                }
                else {
                    buf.push_back(dir);
                }
            }
            
        }
        
        if (buf.empty()) return "/";
        
        string ret = "";
        for (string name : buf) {
            ret += "/";
            ret += name;
        }
        
        return ret;
    }
};