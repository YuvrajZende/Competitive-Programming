#include<bits/stdc++.h>
using namespace std;

int main() {
    cout << "Give the input  ";
    string input;
    getline(cin, input);
    input += "$";
    stack<char> st;

    st.push('$');
    st.push('E');

    int i = 0;

    while (!st.empty()) {
        char top = st.top();
        char cur = input[i];

        if (top == cur) {
            st.pop();
            i++;
        }
        else if (top == 'E' && (cur == 'i' || cur == '(')) {
            st.pop();
            st.push('A');
            st.push('T');
        }
        else if (top == 'A' && cur == '+') {
            st.pop();
            st.push('A');
            st.push('T');
            st.push('+');
        }
        else if (top == 'A' && (cur == ')' || cur == '$')) {
            st.pop();
        }
        else if (top == 'T' && (cur == 'i' || cur == '(')) {
            st.pop();
            st.push('B');
            st.push('F');
        }
        else if (top == 'B' && cur == '*') {
            st.pop();
            st.push('B');
            st.push('F');
            st.push('*');
        }
        else if (top == 'B' && (cur == '+' || cur == ')' || cur == '$')) {
            st.pop();
        }
        else if (top == 'F' && cur == 'i') {
            st.pop();
            st.push('i');
        }
        else if (top == 'F' && cur == '(') {
            st.pop();
            st.push(')');
            st.push('E');
            st.push('(');
        }
        else {
            cout << "Rejected";
            return 0;
        }
    }

    cout << "Accepted";
}
