

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int x ;
        int c = 0; 
        for( x = 1; x<=n+k; x++){
            if((n&x)==0  && abs(n-x)<=k){
                    c+=x;
                }
            }
        return c;
    }
};