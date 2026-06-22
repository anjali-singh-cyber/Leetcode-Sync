

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int v1 = 0;
        int v2 = 0;
        for(int i = 1; i<=n; i++){
            if(i%m==0){
                v2+=i;
            }
            else{
                v1+=i;
            }
        }
        return v1-v2;
    }
};