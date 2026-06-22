

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n-1});

        sort(begin(restrictions), end(restrictions));

        int N = restrictions.size();

        //Left To Right
        for(int i = 1; i < N; i++) {
            int diffDist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i-1][1] + diffDist);
        }

        //Right to Left
        for(int i = N-2; i >= 0; i--) {
            int diffDist       = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1], restrictions[i+1][1] + diffDist);
        }

        int result = 0;

        //Calculating result
        for(int i = 1; i < N; i++) {
            int leftPos = restrictions[i-1][0];
            int leftHt  = restrictions[i-1][1];

            int currPos = restrictions[i][0];
            int currHt  = restrictions[i][1];

            int d      = currPos - leftPos;
            int htDiff = abs(leftHt - currHt);


            int peak = max(leftHt, currHt) + (d - htDiff)/2;

            result = max(result, peak);
        }

        return result;
    }
};

