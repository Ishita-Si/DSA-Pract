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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL) return {-1,-1};

        vector<int> arr;
        ListNode* curr = head -> next;
        ListNode* prev = head;
        ListNode* after = curr -> next;

        int currIdx = 2;

        while(after != NULL){
            if(((curr -> val < prev -> val) && (curr -> val < after -> val)) || ((curr -> val > prev -> val) && (curr -> val > after -> val))){
                arr.push_back(currIdx);
            }
            
            prev = curr;
            curr = after;
            after = after -> next;

            currIdx++;
        }

        if (arr.size() < 2) {
            return {-1, -1};
        }
        
        int maxDiff = arr.back() - arr.front();
        int minDiff = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        return {minDiff,maxDiff};
    }
};