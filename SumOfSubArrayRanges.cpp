#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int minSumOfSubArray(vector<int> &arr)
{
    int n = arr.size();
    const int mod = 1e9 + 7;
    long long ans = 0;
    vector<int> left(n), right(n);
    stack<int> st;

    // Calculate left smaller elements
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
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

    // Clear the stack before calculating right greater elements
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

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = ((sum + (long long)arr[i] * left[i] * right[i]) % mod) % mod;
    }
    return sum;
}
int maxSumOfSubArray(vector<int> &arr)
{
    int n = arr.size();
    const int mod = 1e9 + 7;
    long long ans = 0;
    vector<int> left(n), right(n);
    stack<int> st;

    // Calculate left greater elements
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
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

    // Clear the stack before calculating right greater elements
    while (!st.empty())
    {
        st.pop();
    }

    // Calculate right greater elements

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
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

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = ((sum + (long long)arr[i] * left[i] * right[i]) % mod) % mod;
    }
    return sum;
}

int sumOfSubArrayRanges(vector<int> &arr)
{
    const int mod = 1e9 + 7;
    int minSum = minSumOfSubArray(arr);
    int maxSum = maxSumOfSubArray(arr);
    return ((maxSum - minSum + mod) % mod);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 3, 4, 8, 6, 7, 8, 9, 10};
    cout << "Sum of subarray ranges: " << sumOfSubArrayRanges(arr) << endl;
    return 0;
}