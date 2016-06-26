#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char reversed[] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char rev(char c)
{
    return reversed[isalpha(c) ? c - 'A' : 26 + c - '1'];
}
int main()
{
    string s;
    bool palindrome, mirrored;
    while (cin >> s) {
        palindrome = mirrored = true;
        for (int i = 0, j = s.length() - 1; i < j && palindrome; i++, j--)
            if (s[i] != s[j])
                palindrome = false;
        for (int i = 0, j = s.length() - 1; i <= j && mirrored; i++, j--)
            if (s[i] != rev(s[j]))
                mirrored = false;
        cout << s << " -- is ";
        if (!palindrome && !mirrored)
            cout << "not a palindrome";
        else if (palindrome && !mirrored)
            cout << "a regular palindrome";
        else if (!palindrome && mirrored)
            cout << "a mirrored string";
        else
            cout << "a mirrored palindrome";
        cout << ".\n\n";
    }
    return 0;
}
