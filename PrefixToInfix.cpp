#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

string prefixToInfix(string prefix) {
    stack<string> st;
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            st.push(string(1, c));
        }
        else if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }
    return st.top();
}

int main() {
    string prefix;
    cout << "Enter a prefix expression: ";
    cin >> prefix;

    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}
