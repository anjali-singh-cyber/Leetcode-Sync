

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0; 
        int h = k;
        int n = arr.size();
        int sum = 0;
        int avg = 0; 
        int ans = 0;
        for(int i = l; i<h; i++){
            sum +=arr[i];
        }
        avg = sum/k;
        if(avg>=threshold) ans++;
        while(h<n){
            sum = sum - arr[l] + arr[h];
            avg = sum/k;
            if(avg>=threshold) ans++;
            l++;
            h++;
        }
        return ans;
    }
};