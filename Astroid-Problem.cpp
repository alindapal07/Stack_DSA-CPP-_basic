#include <iostream>
#include <stack>
#include <vector>
#include <algorithm> // Include this for reverse()
using namespace std;

vector<int> asteroidCollision(vector<int> &asteroid)
{
    stack<int> st;

    // Iterate through each asteroid
    for (int i = 0; i < asteroid.size(); i++)
    {
        // If the asteroid is moving to the right, just add it to the stack
        if (st.empty() || asteroid[i] > 0)
        {
            st.push(asteroid[i]);
        }
        else
        {
            // Handle collision
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroid[i]))
            {
                st.pop(); // Pop smaller asteroids
            }
            if (!st.empty() && st.top() == abs(asteroid[i]))
            {
                st.pop(); // Both asteroids destroy each other
            }
            else if (st.empty() || st.top() < 0)
            {
                st.push(asteroid[i]); // The left-moving asteroid survives
            }
        }
    }

    // Collect the result from the stack
    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    // Reverse the result vector to maintain the correct order
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);

    cout << "Resultant asteroids after collision: ";
    for (int asteroid : result)
    {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}
