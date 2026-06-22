

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    int scoreOfString(string s) {
        int sum  = 0; 
        for(int c = 0; c<s.size()-1; c++){
            sum += abs((int)s[c] - (int)s[c+1] );
        }
        return sum; 
    }
};