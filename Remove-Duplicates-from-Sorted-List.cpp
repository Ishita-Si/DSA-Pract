1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* deleteDuplicates(ListNode* head) {
14        if (head == nullptr) return head;
15
16        ListNode* prev = head;
17        ListNode* curr = head->next;
18
19        while (curr != nullptr) {
20            if (curr->val == prev->val) {
21                prev->next = curr->next;   
22                curr = curr->next;
23            } else {
24                prev = curr;            
25                curr = curr->next;
26            }
27        }
28        return head;
29    }
30};