

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int count; 
        for(int i = 0; i<=n; i++){
            int k = i;
            count = 0;
            while(k!=0){
                if(k%2!=0){
                    count++;
                }
                k = k/2;
            }
            ans.push_back(count);

        }
        return ans;
    }
};

// =========================
// Method 2 (cpp)
// =========================

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
         
        for(int i = 0; i<=n; i++){
            
            ans[i] = ans[i>>1] + (i&1);
      }
        return ans;
    }
};