

// =========================
// Method 1 (cpp)
// =========================

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
          for(int i = n; i>0 ; i--){
            bool res = isBadVersion(i);
            if(res==false) return i+1;
          }
          return 1;
    }
};

// =========================
// Method 2 (cpp)
// =========================

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
          for(int i = n; i>0 ; i--){
            bool res = isBadVersion(i);
            if(res==false) return i+1;
          }
          return 1;
    }
};

// =========================
// Method 3 (cpp)
// =========================

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
         int l = 0, h = n; 
         
         while(l<h){
            int mid = l + (h-l)/2;
            if(isBadVersion(mid)){
                h = mid;
            }
            else l = mid + 1;
         }
         return l;
    }
};

// =========================
// Method 4 (cpp)
// =========================

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
         int l = 0, h = n; 
         
         while(l<h){
            int mid = l + (h-l)/2;
            if(isBadVersion(mid)){
                h = mid;
            }
            else l = mid + 1;
         }
         return l;
    }
};