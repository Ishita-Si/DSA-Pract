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
13    ListNode* oddEvenList(ListNode* head) {
14        if(head == nullptr || head->next == nullptr)
15        return head;
16
17        ListNode* odd = head;
18        ListNode* even = head -> next;
19        ListNode* evenHead = even;
20
21        while(even != nullptr && even -> next != nullptr){
22            odd->next = even->next;
23            odd = odd->next;
24            even-> next= odd-> next;
25            even = even->next;
26        }
27
28        odd -> next = evenHead;
29        return head;
30    }
31};