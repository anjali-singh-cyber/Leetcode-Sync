

// =========================
// Method 1 (cpp)
// =========================

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> y;
        ListNode* curr = head;
        while(curr!=nullptr){
            y.push(curr->val);
            curr = curr->next;
        }
        int res = 0; 
        int n = y.size();
        ListNode* now = head;
        for(int i = 1; i<=n/2; i++){
            int sum = 0;
            sum = now->val + y.top();
            now = now->next;
            y.pop();
           res = max(res,sum);
        }

        return res;
    }
};