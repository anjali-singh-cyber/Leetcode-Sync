

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> lessPivot;
        vector<int> equalPivot;
        vector<int> greaterPivot;

        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) {
                lessPivot.push_back(nums[i]);
            } else if(nums[i] == pivot) {
                equalPivot.push_back(nums[i]);
            } else {
                greaterPivot.push_back(nums[i]);
            }
        }

        for(int &num : equalPivot) {
            lessPivot.push_back(num);
        }

        for(int &num : greaterPivot) {
            lessPivot.push_back(num);
        }

        return lessPivot;

    }
};


// -------- Method 2 --------

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> result(n);

        //original nums
        int i = 0;
        int j = n-1;

        //result variables
        int i_ = 0;
        int j_ = n-1;

        while(i < n && j >= 0) {
            if(nums[i] < pivot) {
                result[i_] = nums[i];
                i_++;
            }

            if(nums[j] > pivot) {
                result[j_] = nums[j];
                j_--;
            }

            i++;
            j--;
        }

        //i_ to j_ -> fill the pivot
        while(i_ <= j_) {
            result[i_] = pivot;
            i_++;
        }

        return result;

    }
};
