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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
        return head;
        }
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextNode = curr->next;

            int gcdValue = gcd(curr->val, nextNode->val);
            ListNode* newNode = new ListNode(gcdValue);

            newNode->next = nextNode;
            curr->next = newNode;

            curr = nextNode;
        }

    return head;
    }
};