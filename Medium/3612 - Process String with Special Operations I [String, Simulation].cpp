

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    string processStr(string s) {
        string res = "";

        for(char c : s){
            if(c=='*'){
                if(res==""){
                    continue;
                }
             res.pop_back();
            }
            else if(c=='#'){
                res = res + res;
            }
            else if(c=='%'){
                reverse(res.begin(), res.end());
            }
            else{
                res += c;
            }
        }
        return res;
    }
};