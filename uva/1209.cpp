#include <string>
#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdlib>
using namespace std;
int minimum_absolute_distance_between_consecutive_letters(const string &s)
{
    int d = abs(s[1] - s[0]);
    for (int i = 2; i < s.size(); i++)
        d = min(d, abs(s[i] - s[i - 1]));
    return d;
}
int main()
{
    deque<string> dk;
    string s, tmp;
    while (cin >> s) {
        dk.clear();
        dk.push_back(s);
        tmp = s;
        for (int i = 0; i < 10; i++)
            if (next_permutation(tmp.begin(), tmp.end()))
                dk.push_back(tmp);
            else
                break;
        tmp = s;
        for (int i = 0; i < 10; i++)
            if (prev_permutation(tmp.begin(), tmp.end()))
                dk.push_front(tmp);
            else
                break;
        int d = minimum_absolute_distance_between_consecutive_letters(dk[0]);
        int ans = 0;
        for (int i = 1, t; i < dk.size(); i++)
            if ((t = minimum_absolute_distance_between_consecutive_letters(dk[i])) > d) {
                d = t;
                ans = i;
            }
        cout << dk[ans] << d << '\n';
    }
    return 0;
}
