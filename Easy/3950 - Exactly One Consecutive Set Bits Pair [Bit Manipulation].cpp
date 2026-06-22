

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    bool consecutiveSetBits(int n) {
        if(n==0) return false;
        int count = 0;
        string s = "";
        while(n>0){
            int r = n%2;
            s += std::to_string(r);
            n = n/2;
        }
        std:: reverse(s.begin(),s.end());
        for(int i = 0; i<(int)s.size()-1; i++){
            if(s[i]== '1' && s[i+1]=='1'){
                count++;
            }
            
        }
        if(count==1) return true;
        return false;
    }
};