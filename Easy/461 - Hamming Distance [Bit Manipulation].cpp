

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0; 
        int r = x^y;
        while(r!=0){
            if(r%2!=0){
                count++;
            }
            r = r/2;
        }
        return count;
    }
};