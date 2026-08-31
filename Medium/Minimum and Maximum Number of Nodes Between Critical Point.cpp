class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int pos = 2;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;
        
        while (curr != nullptr && curr->next != nullptr) {
            
            int prevVal = prev->val;
            int currVal = curr->val;
            int nextVal = curr->next->val;
            
            // Check if current node is a critical point
            if ((currVal > prevVal && currVal > nextVal) ||
                (currVal < prevVal && currVal < nextVal)) {
                
                if (first == -1) {
                    first = pos;
                } else {
                    minDist = min(minDist, pos - last);
                }
                
                last = pos;
            }
            
            prev = curr;
            curr = curr->next;
            pos++;
        }
        
        // Less than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }
        
        return {minDist, last - first};
    }
};
