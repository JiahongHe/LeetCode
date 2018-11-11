class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        int N = path.size();
        if (N == 0) return res;
        vector<string> stk;
        stringstream ss(path);
        string tmp;
        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for(auto str : stk) res += "/"+str;
        return res.empty() ? "/" : res;
    }
};