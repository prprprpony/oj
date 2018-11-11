#include<iostream>
using namespace std;
const int N = 1087;
int a[N], b[N], v[N];
int main()
{
    int n,s;
    cin >> n >> s;
    --s;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    int bo = -1;
    for (int i = n-1; i >= 0; --i)
        if (a[i] && b[i]) {
            bo = i;
            break;
        }
    if (a[0] && (a[s] || (bo >= s && b[s])))
        cout << "YES\n";
    else
        cout << "NO\n";
}
