

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> res;
        res.push_back(0);
        int prev = res[0];
        for (int i = 0; i<gain.size(); i++) {
            int k = 0;
            k = gain[i] + prev;
            res.push_back(k);
            prev += gain[i];
        }

        int l = res.size();
        int maxi = 0;
        for (int i = 0; i < l; i++) {
            maxi = max(maxi, res[i]);
        }
        return maxi;
    }
};

// =========================
// Method 2 (cpp)
// =========================

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> res;
        res.push_back(0);
        int prev = res[0];
        for (int i = 0; i<gain.size(); i++) {
            int k = 0;
            k = gain[i] + prev;
            res.push_back(k);
            prev = k;
        }

        int l = res.size();
        int maxi = 0;
        for (int i = 0; i < l; i++) {
            maxi = max(maxi, res[i]);
        }
        return maxi;
    }
};