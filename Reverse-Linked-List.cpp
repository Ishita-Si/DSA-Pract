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
13    ListNode* reverseList(ListNode* head) {
14        if(head == NULL || head->next == NULL){
15            return head;
16        }
17
18        ListNode* prev = NULL;
19        ListNode* curr = head;
20        ListNode* forward = NULL;
21
22        while (curr != NULL){
23            forward = curr->next;
24            curr->next = prev;
25            prev = curr;
26            curr = forward;
27        }
28        return prev;
29    }
30};