

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    int maxDistinct(string s) {
        unordered_map<char,int> map;
        
        for(char k : s){
            map[k]++;
        }

        return map.size();
    }
};