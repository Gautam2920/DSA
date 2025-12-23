#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> s(n);

    cout << "Enter the characters (space separated): ";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    cout << "\nString before reversal: ";
    for (char c : s)
        cout << c << " ";
    cout << endl;

    reverseString(s);

    cout << "String after reversal: ";
    for (char c : s)
        cout << c << " ";
    cout << endl;

    return 0;
}