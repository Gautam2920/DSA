#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
            left++;
        }
        else
        {
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
            right--;
        }
    }
    return water;
}

int main()
{
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid input.\n";
        return 0;
    }

    vector<int> height(n);
    cout << "Enter heights:\n";
    for (int i = 0; i < n; i++)
        cin >> height[i];

    int result = trap(height);

    cout << "Total trapped water: " << result << endl;

    return 0;
}
