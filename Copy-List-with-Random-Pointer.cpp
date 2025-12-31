1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8    
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19    Node* copyRandomList(Node* head) {
20        if (head == nullptr) return nullptr;
21
22        // Step 1: insert copies
23        Node* curr = head;
24        while (curr != nullptr) {
25            Node* copy = new Node(curr->val);
26            copy->next = curr->next;
27            curr->next = copy;
28            curr = copy->next;
29        }
30
31        // Step 2: assign random pointers
32        curr = head;
33        while (curr != nullptr) {
34            if (curr->random != nullptr)
35                curr->next->random = curr->random->next;
36            curr = curr->next->next;
37        }
38
39        // Step 3: separate lists
40        Node* dummy = new Node(0);
41        Node* copyCurr = dummy;
42        curr = head;
43
44        while (curr != nullptr) {
45            copyCurr->next = curr->next;
46            curr->next = curr->next->next;
47
48            copyCurr = copyCurr->next;
49            curr = curr->next;
50        }
51
52        return dummy->next;
53    }
54};
55