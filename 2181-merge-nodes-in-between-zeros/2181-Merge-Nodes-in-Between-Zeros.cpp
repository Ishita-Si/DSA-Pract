class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* mod = head->next;
        int total = 0;
        
        while (curr) {
            if (curr->val != 0) {
                total += curr->val;
            } else {
                mod->val = total;
                total = 0;
                ListNode* nextNode = curr->next;
                
                if (nextNode == nullptr) {
                    mod->next = nullptr;
                } else {
                    mod = mod->next;
                }
            }
            curr = curr->next;
        }
        
        return head->next;
    }
};
