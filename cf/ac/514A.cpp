#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if ('5' <= s[0] && s[0] < '9')
        s[0] = '9' - s[0] + '0';
    for (int i = 1; i < s.size(); ++i)
        if (s[i] >= '5')
            s[i] = '9' - s[i] + '0';
    cout << s << '\n';
}
