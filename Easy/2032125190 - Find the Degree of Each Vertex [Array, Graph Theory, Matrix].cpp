

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> ans ;
        int count;
        for(int i =0 ; i<matrix.size(); i++){
            count = 0;
         for(int j =0 ; j<matrix.size(); j++){
            if(matrix[i][j]==1){
                count++;
            }
         }
         ans.push_back(count);

        }
        return ans;
    }
};