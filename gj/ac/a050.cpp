#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int r = 1; r <= n; r++)
        for (int l = 1; l <= n; l++)
            cout << l << 'x' << r << '=' << setw(2) << l * r << (l != n ? "  " : "\n");
    return 0;
} 
