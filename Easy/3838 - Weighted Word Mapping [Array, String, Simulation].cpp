

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string h = "";
        for(string c : words){
            int sum = 0; 
            for( char k : c){
                sum += weights[k-'a'];
            }
            int t = sum%26;
            h += 'z' - t;
        }
        return h;
    }
};

// -------- Method 2 --------

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string h = "";
        for(string c : words){
            int sum = 0; 
            for( char k : c){
                sum += weights[k-'a'];
            }
            int t = sum%26;
            h += 'z' - t;
        }
        return h;
    }
};