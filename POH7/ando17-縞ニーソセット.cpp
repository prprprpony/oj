#include <iostream>
using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cout << ((i / n & 1) ? 'W' : 'R');
    cout << '\n';
    return 0;
}
