

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum = costs[0], count = 0; 
        if(sum>coins){
            return 0;
        }
        else {
            count++;
            }
        for(int i=1; i<costs.size(); i++){
            
            if(sum+ costs[i]<=coins){
                sum += costs[i];
                count++;
            }
        }
        return count;
    }
};

// -------- Method 2 --------

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum = costs[0], count = 0; 
        if(sum>coins){
            return 0;
        }
        else {
            count++;
            }
        for(int i=1; i<costs.size(); i++){
            
            if(sum+ costs[i]<=coins){
                sum += costs[i];
                count++;
            }
            else break;
        }
        return count;
    }
};

// -------- Method 3 --------

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum = costs[0], count = 0; 
        if(sum>coins){
            return 0;
        }
        else {
            count++;
            }
        for(int i=1; i<costs.size(); i++){
            
            if(sum+ costs[i]<=coins){
                sum += costs[i];
                count++;
            }
            else break;
        }
        return count;
    }
};

// -------- Method 4 --------

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum = costs[0], count = 0; 
        if(sum>coins){
            return 0;
        }
        else {
            count++;
            }
        for(int i=1; i<costs.size(); i++){
            
            if(sum + costs[i]<=coins){
                sum += costs[i];
                count++;
            }
            else break;
        }
        return count;
    }
};