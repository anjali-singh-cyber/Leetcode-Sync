

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    bool checkGoodInteger(int n) {
        int di = 0; 
        int sq = 0;
        while(n!=0){
            int d = n%10;
            di += d;
            sq += d*d;
            n = n/10;
        }
        if((sq-di)>=50){
            return true;
        }
        else return false;
    }
};