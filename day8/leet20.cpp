#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;

    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cout << "Enter the string of brackets: ";
    cin >> s;

    if (isValid(s))
        cout << "The string is valid.\n";
    else
        cout << "The string is not valid.\n";

    return 0;
}
