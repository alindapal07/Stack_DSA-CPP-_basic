#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<limits.h>
using namespace std;

int largestRectangleArea(vector<int>& heights){
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0);     
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int top = st.top();
            st.pop();
            int area = heights[top] * (st.empty() ? i : i - st.top() - 1);
            maxArea = max(maxArea, area);
        } 
        st.push(i);   
    }
    return maxArea;      
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int maxArea = 0; 
    int cols = matrix[0].size();
    vector<int> height(cols, 0);

    for (int row = 0; row < matrix.size(); ++row) {
        for (int col = 0; col < cols; ++col) {
            if (matrix[row][col] == 1) {
                height[col] += 1;
            } else {
                height[col] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(height));
    }
    return maxArea;   
}

int main() {
    vector<vector<int>> matrix = 
    {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
    };
    int maxArea = maximalRectangle(matrix);
    cout << "Maximal Rectangle Area: " << maxArea << endl; 
    return 0;
}
