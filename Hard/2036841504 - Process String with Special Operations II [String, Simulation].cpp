

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    char processStr(string s, long long k){
    int n = s.size(); 
        long long y = 0;

        for(char c : s){
            if(c == '*'){
                if(y > 0){
                    y--;
                }
                }
                else if(c == '#'){
                   y = y*2; 
                }
                else if(c == '%'){
                    continue;
                }
                else{
                y++;
            }
        }
        
        if(k >= y){
            return '.';
        }
        for(int i = n-1; i>=0; i--){
            if(s[i]== '*'){
                y++;
            }
            else if(s[i] == '%'){
                k = y-k-1;
            }
            else if(s[i] == '#'){
                y = y/2;
                k = (k>=y)?k-y: k;
            }
            else{
                y--;
            }
            if(k==y){
                return s[i];
            }
        }
        return '.';
    }
};