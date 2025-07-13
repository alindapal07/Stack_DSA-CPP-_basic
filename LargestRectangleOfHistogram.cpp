#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int largestRectangleOfHistogram(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int height = heights[st.top()];
            st.pop();
            int right = i;
            int left = st.empty() ? -1 : st.top();
            int width = right - left - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int height = heights[st.top()];
        st.pop();
        int right = n;
        int left = st.empty() ? -1 : st.top();
        int width = right - left - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = largestRectangleOfHistogram(heights);
    cout << "The area of the largest rectangle in the histogram is: " << result << endl;
    return 0;
}
