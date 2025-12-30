#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> seen;
    seen.reserve(nums.size());

    for (int num : nums)
    {
        if (seen.count(num))
            return true;
        seen.insert(num);
    }
    return false;
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
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    if (containsDuplicate(nums))
        cout << "The array contains duplicates.\n";
    else
        cout << "The array does not contain duplicates.\n";

    return 0;
}
