#include<bits/stdc++.h>
using namespace std;
bool ok(int y,int p)
{
    for (int i = 2; i * i <= y && i <= p; ++i)
        if (y % i == 0)
            return 0;
    return 1;
}
int main()
{
    int p, y;
    cin >> p >> y;
    for (;y > p && !ok(y,p); --y);
    cout << (y > p ? y : -1) << endl;
}
