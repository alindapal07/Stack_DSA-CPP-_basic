#include<iostream>
#include<stack>
using namespace std;
#include<string>

bool isoperator(char c) {
    return c=='+'|| c=='-'|| c=='*'|| c=='/'|| c=='^';
}

string postfixToInfix(string postfix) {
    stack<string> st;
    for(char c : postfix) {
        if (isalnum(c)) 
            st.push(string(1, c)); 
        else if (isoperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string expr = "(" + op1 + c + op2 + ")"; 
            st.push(expr); 
        }   
    }
    return st.top(); 
}

int main(){
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
  return 0;
}