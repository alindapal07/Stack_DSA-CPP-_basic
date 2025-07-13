#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> previousSmallerElement(vector<int>& arr){
        int n=arr.size();
        vector<int> result(n,-1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while(!st.empty() && st.top()>= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                result[i]=st.top();
            }
            st.push(arr[i]);
        }
        return result;      
}

int main(){
    vector<int> arr={4, 5, 2, 10, 8};
    vector<int> result = previousSmallerElement(arr);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}