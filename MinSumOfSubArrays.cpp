#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int MinSumOfSubArrays(vector<int> &arr)
{
    int n = arr.size();
    const int mod = 1e9 + 7;
    stack<int> st;
    vector<int> left(n), right(n);

    // Calculate left smaller elements
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            left[i] = i + 1;
        }
        else
        {
            left[i] = i - st.top();
        }
        st.push(i);
    }

    // clearing the stack before calculating right greater elements

    while (!st.empty())
    {
        st.pop();
    }

    // Calculate right greater elements

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            right[i] = n - i;
        }
        else
        {
            right[i] = st.top() - i;
        }
        st.push(i);
    }

    // calculate the sum of all subarrays

    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        long long contribution = (long long)arr[i] * left[i] * right[i];
        sum = (sum + contribution) % mod;
    }
    return sum;
}

int main()
{
    vector<int> arr = {1, 3, 2, 4};
    int result = MinSumOfSubArrays(arr);
    cout << "Minimum sum of all subarrays: " << result << endl;
    return 0;
}