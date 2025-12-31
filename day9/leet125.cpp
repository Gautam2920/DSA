#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int left = 0, right = s.length() - 1;

    while (left < right)
    {
        if (!isalnum(static_cast<unsigned char>(s[left])))
            left++;
        else if (!isalnum(static_cast<unsigned char>(s[right])))
            right--;
        else
        {
            if (tolower(static_cast<unsigned char>(s[left])) !=
                tolower(static_cast<unsigned char>(s[right])))
                return false;
            left++;
            right--;
        }
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    if (isPalindrome(s))
        cout << "The string is a palindrome.\n";
    else
        cout << "The string is not a palindrome.\n";

    return 0;
}
