#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> previousSmallerElements(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = arr[st.top()];
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = previousSmallerElements(arr);
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << "The previous smaller element of " << arr[i] << " is " << ans[i] << endl;
    }
    return 0;
}