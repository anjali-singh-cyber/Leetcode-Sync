

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxEl = INT_MIN;
        int minEl = INT_MAX;

        for (int& num : nums) {
            maxEl = max(maxEl, num);
            minEl = min(minEl, num);
        }

        return 1LL * (maxEl - minEl) * k;
    }
};

// -------- Method 2 --------

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
       for(int i = 0; i<n; i++){
            maxi = max(nums[i],maxi);
            mini = min(nums[i],mini);
       }
       return 1L*k*(maxi-mini);
    }
};

// -------- Method 3 --------

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
       for(int i = 0; i<n; i++){
            maxi = max(nums[i],maxi);
            mini = min(nums[i],mini);
       }
       return 1L*k*(maxi-mini);
    }
};