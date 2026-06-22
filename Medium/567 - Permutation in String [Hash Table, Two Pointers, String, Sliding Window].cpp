

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> eww(26,0);
        for(int i = 0; i<s1.size();i++){
            eww[s1[i]-'a']++;
        }
        int l = 0;
        int h = s1.size() -1;
        while(h<s2.size()){
            vector<int>next(26,0);
            for(int i = l ; i<=h; i++){
                next[s2[i]-'a']++;
            }
            if(next==eww){
                return true;
            }
            l++;
            h++;
        }

        return false;
    }
};

// -------- Method 2 --------

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> eww(26, 0);
        if(s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            eww[s1[i] - 'a']++;
        }

        int l = 0;
        int h = s1.size();
        vector<int> next(26, 0);
        for (int i = l; i<h; i++) {
                next[s2[i] - 'a']++;
            }
             if (next == eww) {
                return true;
            }
        while (h < s2.size()) {
            next[s2[l] - 'a']--;
            next[s2[h] - 'a']++;
             if (next == eww) {
                return true;
            }
            l++;
            h++;
        }

        return false;
    }
};

// -------- Method 3 --------

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> eww(26, 0);
        if(s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            eww[s1[i] - 'a']++;
        }

        int l = 0;
        int h = s1.size();
        vector<int> next(26, 0);
        for (int i = l; i<h; i++) {
                next[s2[i] - 'a']++;
            }
             if (next == eww) {
                return true;
            }
        while (h < s2.size()) {
            next[s2[l] - 'a']--;
            next[s2[h] - 'a']++;
             if (next == eww) {
                return true;
            }
            l++;
            h++;
        }

        return false;
    }
};

// -------- Method 4 --------

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> eww(26, 0);
        
        for (int i = 0; i < s1.size(); i++) {
            eww[s1[i] - 'a']++;
        }
        int l = 0;
        int h = s1.size();
        vector<int> next(26, 0);
        for (int i = l; i<h; i++) {
                next[s2[i] - 'a']++;
            }
             if (next == eww) {
                return true;
            }
        while (h < s2.size()) {
            next[s2[l] - 'a']--;
            next[s2[h] - 'a']++;
             if (next == eww) {
                return true;
            }
            l++;
            h++;
        }

        return false;
    }
};


// -------- Method 5 --------

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> eww(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            eww[s1[i] - 'a']++;
        }
        int matches = 0;
        int l = 0;
        int h = s1.size();
        vector<int> next(26, 0);
        for (int i = l; i < h; i++) {
            next[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (next[i] == eww[i]) {
                matches++;
            }
        }
        if (matches == 26)
            return true;
        while (h < s2.size()) {
            int c1 = s2[l] - 'a';
            if (next[c1] == eww[c1])
                matches--;
            next[c1]--;
            if (next[c1] == eww[c1])
                matches++;

            int c2 = s2[h] - 'a';
            if (next[c2] == eww[c2])
                matches--;
            next[c2]++;
            if (next[c2] == eww[c2])
                matches++; 
                
            if (matches == 26)
               return true;

            
            l++;
            h++;
        }

        return false;
    }
};
