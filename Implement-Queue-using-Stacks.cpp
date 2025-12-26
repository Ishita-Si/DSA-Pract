1class MyQueue {
2private:
3    stack<int> inStack;
4    stack<int> outStack;
5
6    void transfer() {
7        while (!inStack.empty()) {
8            outStack.push(inStack.top());
9            inStack.pop();
10        }
11    }
12
13public:
14    MyQueue() {}
15
16    void push(int x) {
17        inStack.push(x);
18    }
19
20    int pop() {
21        if (outStack.empty()) {
22            transfer();
23        }
24        int front = outStack.top();
25        outStack.pop();
26        return front;
27    }
28
29    int peek() {
30        if (outStack.empty()) {
31            transfer();
32        }
33        return outStack.top();
34    }
35
36    bool empty() {
37        return inStack.empty() && outStack.empty();
38    }
39};
40