

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    int maxDepth(string s) {
        int counter = 0; 
        int maxCount = INT_MIN;
        for(int i = 0; i<s.size(); i++){
            if(s[i]=='('){
                counter++;
            }
            else if(s[i]==')'){
                counter--;
            }
            maxCount = max(maxCount,counter);
        }
        return maxCount;
    }
};