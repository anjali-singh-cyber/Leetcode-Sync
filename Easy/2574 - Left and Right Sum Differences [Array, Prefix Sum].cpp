

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int ls = 0; 
        int rs = 0; 
        for(int i = 0; i<n; i++){
            ls = 0;
            rs = 0;
            if(i==0){
                for(int j = 1; j<n; j++){
                    rs += nums[j];
                }
            }
            else if(i==n-1){
                for(int j = 0; j<n-1; j++){
                    ls += nums[j];
                }
            }
            else{
                for(int j = i+1; j<n; j++){
                    rs += nums[j];
                }
                for(int j = 0; j<i; j++){
                    ls += nums[j];
                }
            }
            ans.push_back(abs(ls-rs));

        }
        return ans;
    }
};