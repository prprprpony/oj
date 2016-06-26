#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << s;
        cout << (i != n - 1 ? '_' : '\n');
    }
    return 0;
}
