void insertAtBottom(stack<int>& s, int x) {
    if (s.size() == 0) {
        s.push(x);
    } else {
        int a = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(a);
    }
}

void reverse(stack<int>& s) {
    if (s.size() > 0) {
        int x = s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s, x);
    }
}
