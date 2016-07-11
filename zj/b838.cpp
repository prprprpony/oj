#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(42, '\n');
    while (t--) {
        int s = 0, pairs = 0, c;
        bool ok = true;
        while ((c = cin.get()) != '\n') {
            if (c != '(' && c != ')')
                continue;
            if (c == '(') {
                ++s;
            } else if (ok && s) {
                --s;
                ++pairs;
            } else {
                ok = false;
            }
        }
        cout << ((ok && !s) ? pairs : 0) << '\n';
    }
}
