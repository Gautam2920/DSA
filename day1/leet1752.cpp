#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{
    int dropCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > nums[(i + 1) % nums.size()])
        {
            dropCount++;
            if (dropCount > 1)
                return false;
        }
    }
    return true;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    bool result = check(nums);

    if (result)
        cout << "The array IS sorted and rotated." << endl;
    else
        cout << "The array is NOT sorted and rotated." << endl;

    return 0;
}