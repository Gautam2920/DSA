#include <iostream>
#include <stack>
#include <string>
using namespace std;

string minRemoveToMakeValid(string s)
{
    stack<int> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')')
        {
            if (!st.empty())
                st.pop();
            else
                s[i] = '#';
        }
    }

    while (!st.empty())
    {
        s[st.top()] = '#';
        st.pop();
    }

    string result;
    for (char ch : s)
    {
        if (ch != '#')
            result.push_back(ch);
    }

    return result;
}

int main()
{
    string input;
    cout << "Enter the string: ";
    getline(cin, input);
    string output = minRemoveToMakeValid(input);
    cout << "Valid parentheses string: " << output << endl;
    return 0;
}
