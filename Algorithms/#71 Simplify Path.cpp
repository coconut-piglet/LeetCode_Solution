class Solution {
public:
    string simplifyPath(string path) {
        int len;
        string dir;
        list<string> buf;
        
        path += '/';
        len = path.length();
        
        for (int i = 0; i < len; i++) {
            
            if (path[i] != '/') {
                dir += path[i];
            }
            else {
                if (dir.compare("..") == 0) {
                    if (!buf.empty()) buf.pop_back();
                }
                else if (dir.length() != 0 && dir.compare(".") != 0) {
                    buf.push_back(dir);
                }
                dir = "";
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