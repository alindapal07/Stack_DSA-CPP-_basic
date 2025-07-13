#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

string removeKdigits(string num, int k)
{
    if (num.size() <= k)
        return "0";
    if (k == 0)
        return num;
    stack<char> st;
    for (int i = 0; i < num.size(); i++)
    {
        while (!st.empty() && k > 0 && num[st.top()] > num[i])
        {
            st.pop();
            k--;
        }
        st.push(i);
    }
    while (k > 0)
    {
        st.pop();
        k--;
    }
    string res = "";
    while (!st.empty())
    {
        res += num[st.top()];
        st.pop();
    }
    while (res.size() != 0 && res.back() == '0')
    {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    if (res.size() == 0)
        return 0;
    return res;
}

int main()
{
    string num = "1432219";
    int k = 3;
    string result = removeKdigits(num, k);
    cout << "The smallest number after removing " << k << " digits from " << num << " is: " << result << endl;
    return 0;
}
