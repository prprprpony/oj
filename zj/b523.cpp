#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    set<string> h;
    while (getline(cin, s)) {
        if (h.count(s))
            cout << "YES\n";
        else {
            cout << "NO\n";
            h.insert(s);
        }
    }
}
