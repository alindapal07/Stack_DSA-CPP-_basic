#include<iostream>
#include<stack>
using namespace std;

class MinStack {
    private:
        stack<long long> st;
        long long minElement;
    public:
        void push(int val) {
            if (st.empty())
            {
                st.push(val);
                minElement = val;
            }
            else if(val<minElement) {
              st.push(2*val - minElement);
              minElement = val;    
        }
        else{
            st.push(val);
        }
        }

        void pop() {
            if (st.empty()) throw runtime_error("Stack is empty");
            long long top=st.top();
            st.pop();
            if (top< minElement) {
                minElement = 2*minElement-top;
            }
        }

        int top() {
           if (st.empty()) throw runtime_error("Stack is empty");
            long long top=st.top();
            st.pop();
            if(top>minElement) {
                return top;
            }
            else {
                return minElement;            }
           
        }

        int getMin() {
            if (st.empty()) throw runtime_error("Stack is empty");
            return minElement;
        }

        bool isEmpty() {
            return st.empty();
        }
};



int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum: " << minStack.getMin() << endl;
    minStack.pop();
    cout << "Top: " << minStack.top() << endl;
    cout << "Minimum: " << minStack.getMin() << endl;
    return 0;
}