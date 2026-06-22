

// =========================
// Method 1 (cpp)
// =========================

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double moveh;
        if(hour==12){
            moveh = minutes*0.5;
        }
        else{
        moveh = minutes*0.5 + hour*30;
        }
        double movem = minutes*6;
        double ans = abs(movem - moveh);
        if(ans>180){
            return 360 - ans;
        }
        else return ans;
    }
};