

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res;
        string k ;
        for(int i = 0; i<m; i++){
            k = "";
            for(int j = 0; j<n ; j++){
                if(i==0 || j==n-1){
                    k += '.' ;
                }
                else{
                    k += '#';
                }
            }
            res.push_back(k);
        }
        return res;
    }
};