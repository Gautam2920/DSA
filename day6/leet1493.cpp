#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int left = 0, zeroCount = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
            zeroCount++;

        while (zeroCount > 1)
        {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }
        maxLen = max(maxLen, right - left);
    }

    return maxLen;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid array size.\n";
        return 0;
    }

    vector<int> nums(n);
    cout << "Enter binary elements (0s and 1s only):\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int result = longestSubarray(nums);

    cout << "Length of the longest subarray of 1s after deleting one element is: "
         << result << endl;

    return 0;
}
