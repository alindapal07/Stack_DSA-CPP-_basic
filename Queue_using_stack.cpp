#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class myQueue
{
    stack<int> s1;
    stack<int> s2;
public:
    void enqueue(int x)
    {
        while (!s1.empty())
        {
          s2.push(s1.top());
          s1.pop();
        }
        s1.push(x);

        while (!s2.empty())
        {
           s1.push(s2.top());
           s2.pop();
        }
         
    }

    int dequeue(){
         if (s1.empty()) return -1;
         else{
           int x=s1.top();
           s1.pop();
           return x;
         }
         
    }
};


int main() {
    myQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 

    return 0;
}
