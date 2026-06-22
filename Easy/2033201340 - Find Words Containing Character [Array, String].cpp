

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int i = 0;
        vector<int> ans;
        for(string c : words){
            for(char k : c){
                if(k==x){
                    ans.push_back(i);
                    break;
                }
            }
            i++;
        }
        return ans;
    }
};