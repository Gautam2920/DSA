#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    int freq[26] = {0};

    for (char c : s)
        freq[c - 'a']++;

    for (int i = 0; i < s.size(); i++)
        if (freq[s[i] - 'a'] == 1)
            return i;

    return -1;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int index = firstUniqChar(s);

    if (index == -1)
        cout << "No unique character found.\n";
    else
        cout << "Index of first unique character: " << index << endl;

    return 0;
}
