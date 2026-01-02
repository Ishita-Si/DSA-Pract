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
13    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
14        if(list1 == nullptr || list2 == nullptr){
15            return list1 == nullptr ? list2 : list1;
16        }
17        if(list1 -> val <= list2 -> val){
18            list1 -> next = mergeTwoLists(list1->next,list2);
19            return list1;
20        }else{
21            list2 -> next = mergeTwoLists(list1,list2->next);
22            return list2;
23        }
24    }
25};