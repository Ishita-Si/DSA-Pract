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
13    ListNode* insertionSortList(ListNode* head) {
14        if (!head || !head->next) return head;
15
16        ListNode dummy(0);
17        ListNode* curr = head;
18
19        while (curr) {
20            ListNode* nextNode = curr->next;
21
22            ListNode* prev = &dummy;
23            while (prev->next && prev->next->val < curr->val) {
24                prev = prev->next;
25            }
26
27            curr->next = prev->next;
28            prev->next = curr;
29
30            curr = nextNode;
31        }
32        return dummy.next;
33    }
34};