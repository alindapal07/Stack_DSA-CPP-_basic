#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> nextGreaterElement(vector <int>& nums)
{
    int n=nums.size();
    vector<int> result(n,-1);
    stack<int> st;
    for (int i = n-1;i>=0;--i)
    {
        while(!st.empty() && st.top() <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
           result[i] = st.top();
        }
        st.push(nums[i]);
    }
    return result;
}

int main(){
      vector <int> nums={4, 5, 2, 10, 8};
      vector<int> result = nextGreaterElement(nums);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
        cout << endl;
        return 0;
    }