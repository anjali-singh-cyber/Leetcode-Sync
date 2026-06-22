

// =========================
// Language: cpp
// =========================



// -------- Method 1 --------

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;
        
        ListNode* slow      = head;
        ListNode* fast      = head->next->next;
        
        while(fast && fast->next) {
            slow     = slow->next;
            
            fast     = fast->next->next;
        }
        
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete(toDelete);
        
        return head;
    }
};

// -------- Method 2 --------

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr){
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            prev = slow; 
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        slow->next = nullptr;

        
        return head;
    }
};