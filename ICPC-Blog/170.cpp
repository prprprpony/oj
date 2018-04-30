#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 1 + 33 * 2 + 1;
    cout << n  << endl;
    cout << 2 << ' ' << 3 << endl;
    for (int i = 2; i < 65; ++i) {
        int c = i + 2 > n ? 0 : i + 2;
        if (i & 1)
            cout << c << " 0\n";
        else
            cout << "0 " << c << endl;
    }
    cout << "67 68" << endl;
    cout << "0 0" << endl;
    cout << "0 0" << endl;
    cout << "0 0" << endl;
}
